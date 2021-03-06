/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  /**
   * Редирект на страницу "нет мобильной версии"
   * @type {{attach: attach}}
   * @fixme: Убрать
   */
  /*
  Drupal.behaviors.nomobileversion = {
    attach: function (context) {
      if (String(location.href).indexOf('nomobileversion') == -1 && $(window).width() <= 640 && $(window).height() <= 480) {
        location.href = '/nomobileversion';
      }
    }
  }
  */

  Drupal.behaviors.HintFormElemements = {
    attach: function (context, settings) {
      $('body.page-dataset .exposed-search-form .views-exposed-form .views-widget-filter-search_api_views_fulltext input').attr('placeholder', Drupal.t('Search for datasets'));
      $('body.page-apps .views-exposed-form .views-widget-filter-search_api_views_fulltext input').attr('placeholder', Drupal.t('Search for applications'));

      //if (settings.facetapi && settings.facetapi.facets && settings.facetapi.facets.length > 0) {
        /*$('body.page-dataset .exposed-search-form .views-exposed-form .views-submit-button input').unbind('click').click(function(e) {
          Drupal.ajax_facets.sendAjaxQuery($(this), new Array());
          e.preventDefault();
        });*/
      //}

      if ($('.pane-gb-search-pane .form-text, .pane-datasets-search-dataset-search .view-filters .form-text').length > 0) {
        $('.pane-gb-search-pane .form-text').attr("placeholder", Drupal.t("Search for data"));
        $('.pane-datasets-search-dataset-search .view-filters .form-text').attr("placeholder", Drupal.t("Search for data"));
        //$('input[placeholder], textarea[placeholder]').inputHints();
      }
    }
  } 
  
//  Drupal.behaviors.TaxonomyColumns = {
//    attach: function (context) {
//      $('.section-rubriki .view-rubric-nodes .view-content, .section-rubrics .view-rubric-nodes .view-content', context).once('massontry', function() {
//        var massontry = $(this);
//        $('<div class="view-header"></div>').prependTo(massontry);
//        var $container = $('.view-rubric-nodes .view-content');
//        var msnry = new Masonry( $container.get(0), {
//          // options
//          //columnWidth: 200,
//          itemSelector: '.views-row'/**/,
//          gutter: '.view-rubric-nodes .view-content .view-header'
//        });
//      });
//    }
//  }

  Drupal.behaviors.MobileDatasetColumns = {
    attach: function (context) {
      $('.region-mobile-change .show-result').click(function(){
        $('.region-facet, .rubric-menu, .show-result, .dataset-right-col').animate({left: -8000}).hide();
        $('.hide-result, .dataset-search-facets, .rubric-content, .right-column-apps, .dataset-left-col').show().animate({right: 0});
        
        return false;
      });
      $('.region-mobile-change .hide-result').click(function(){
        $('.hide-result, .dataset-search-facets, .rubric-content, .right-column-apps, .dataset-left-col').animate({right: -8000}).hide();
        $('.region-facet, .show-result, .rubric-menu, .dataset-right-col').animate({left: 0}, function() {
          window.msnry.layout();
        }).show();
        return false;
      });
    }   
  }

  Drupal.behaviors.TaxonomyColumnsRubric = {
    attach: function (context) {
      // Do not apply to other pages
      if ($('.page-taxonomy-term .rubric-content .view').length == 0) {
        return;
      }

      // In this we should use context and don't use once()
      $('.view-content', context).not('.page-taxonomy-term-datasets .rubric-content .view .view-content').once('massontry', function() {
        var massontry = $(this);
        $('<div class="view-header"></div>').prependTo(massontry);
        var container = document.querySelector('.page-taxonomy-term .rubric-content .view .view-content');
        var msnry = new Masonry( container, {
          // options
          //columnWidth: 200,
          itemSelector: '.views-row',
          gutter: '.page-taxonomy-term .rubric-content .view .view-content .view-header'
        });

        window.msnry = msnry;

        setTimeout(function() {
          msnry.layout();
        }, 50);
      });
    }
  }




  Drupal.behaviors.ActiveElement = {
    attach: function (context, settings) {

      // Add class for active elements.
      $('input[type="radio"][checked]', context)
        .parent().addClass('active-element');
        
      // Add event for detect active elements.
      $('input[type="radio"]', context).once().change(function() {
        // Find form element for context.
        var $this = $(this),
            $form = $this.parents('form');

        // Remove class from over elements with same name.
        $form.find('input[type="radio"][name="' + $this.attr('name') + '"]')
          .parent().removeClass('active-element');

        // Add class for active element.
        $this.parent().addClass('active-element');
      });         
    }
  }  

  Drupal.behaviors.QuickFacts = {
    attach: function (context, settings) {  
      /**/  if('.view-quick-facts .view-content') {
        var n = 0;
        var $fact = $('.view-quick-facts .view-content .views-row');
        $($fact[n]).addClass('next');

         setInterval(function(){
          $($fact[n]).removeClass('next');
          if(n+1 == $fact.length) {
            n = 0;
          } else {
            n++;
          }
          setTimeout(function(){
            $($fact[n]).addClass('next');
          }, 500)
        }, 6000);
      }   
    }
  }

  /*Drupal.behaviors.resizeMainMenu = {
    attach: function(context, settings) {
      if($('body').width() > 1200) {
        var width_menu = $('.region-header .pane-system-main-menu > ul').width();
        $('.pane-gb-search-pane').width(width_menu);            
      }
    }
  } */   
  
  Drupal.behaviors.positionActiveMenu = {
    attach: function(context, settings) {  
      $(".not-front .region-header").addClass("active-region");
      $('.region-header .pane-system-main-menu > ul > li.sfHover').livequery(function(){
        if($(this).hasClass('sfHover')) {
          var li = $(this);
          var half_link_width = li.width()/2;
          var ul = li.children('ul');
          var item = 2; 
          ul.find("li").each(function(){
            item = item + $(this).width();
          });
          var margin = -item/2 + half_link_width;
          ul.css({
            width: item
            //"margin-left": margin
          }); 
          // кастомное положение блоков
          if($(this).hasClass("sf-item-1")) { // 
            if($('body').width() > 765 && $('body').width() < 1200) {
              ul.css({
                "margin-left": "-111px"
              });              
            } 
            else {            
              ul.css({
                "margin-left": "-227px"
              }); 
            }
          }            
          if($(this).hasClass("sf-item-3")) { //
            if($('body').width() > 765 && $('body').width() < 1200) {
              ul.css({
                "margin-left": "-106px"
              });              
            } 
            else {
              ul.css({
                "margin-left": "-150px"
              });              
            }
            //alert($('body').width());  
          } 
          if($(this).hasClass("sf-item-4")) { //
            if($('body').width() > 765 && $('body').width() < 1200) {
              // custom position for english version
              if($('body').hasClass('i18n-en')) {
                ul.css({
                  "margin-left": "-22px"
                });                  
              }
              else {
                ul.css({
                  "margin-left": "-259px"
                });                  
              }           
            } 
            else {           
              // custom position for english version
              if($('body').hasClass('i18n-en')) {
                ul.css({
                  "margin-left": "-26px"
                });                 
              }
              else {
                ul.css({
                  "margin-left": "-306px"
                });                  
              }                
            }
          } 
          if($(this).hasClass("sf-item-6")) { //
             if($('body').width() > 765 && $('body').width() < 1200) {
              ul.css({
                "margin-left": "-142px"
              });              
            } 
            else {             
              ul.css({
                "margin-left": "-165px"
              });  
            }
          } 
          if($(this).hasClass("sf-item-7")) { //
             if($('body').width() > 765 && $('body').width() < 1200) {
              ul.css({
                "margin-left": "-655px"
              });              
            } 
            else {             
              ul.css({
                "margin-left": "-742px"
              });  
            }
          }          
        }
      });
    
    }
  }
  
  Drupal.behaviors.preventClickHrefUserMenu = {
    attach: function(context, settings) {
      //$('.region-header .pane-system-main-menu > ul > li > a').click(function(e) {
      var handler = function(e) {
        if(!$(this).parent("li").hasClass("sf-item-2")){
          $(".region-header").addClass("active-region");
          var half_link_width = $(this).width()/2;
          var ul = $(this).next("ul");
          var item = 2; 
          ul.find("li").each(function(){
            item = item + $(this).width();
          });
          var margin = half_link_width - item/2;
          ul.css({
            width: item
            //"padding-top": half_link_width,
            //"margin-left": margin
          });  
          // кастомное положение блоков
          if($(this).hasClass("sf-item-1")) { // 
            if($('body').width() > 765 && $('body').width() < 1200) {
              ul.css({
                "margin-left": "-111px"
              });              
            } 
            else {            
              ul.css({
                "margin-left": "-227px"
              }); 
            }
          }            
          if($(this).hasClass("sf-item-3")) { //
            if($('body').width() > 765 && $('body').width() < 1200) {
              ul.css({
                "margin-left": "-106px"
              });              
            } 
            else {
              ul.css({
                "margin-left": "-150px"
              });              
            }
            //alert($('body').width());  
          } 
          if($(this).hasClass("sf-item-4")) { //
            if($('body').width() > 765 && $('body').width() < 1200) {
              // custom position for english version
              if($('body').hasClass('i18n-en')) {
                ul.css({
                  "margin-left": "-22px"
                });                  
              }
              else {
                ul.css({
                  "margin-left": "-259px"
                });                  
              }           
            } 
            else {           
              // custom position for english version
              if($('body').hasClass('i18n-en')) {
                ul.css({
                  "margin-left": "-26px"
                });                 
              }
              else {
                ul.css({
                  "margin-left": "-306px"
                });                  
              }                
            }
          }  
          if($(this).hasClass("sf-item-6")) { //
             if($('body').width() > 765 && $('body').width() < 1200) {
              ul.css({
                "margin-left": "-142px"
              });              
            } 
            else {             
              ul.css({
                "margin-left": "-165px"
              });  
            }
          } 
          if($(this).hasClass("sf-item-7")) { //
             if($('body').width() > 765 && $('body').width() < 1200) {
              ul.css({
                "margin-left": "-655px"
              });              
            } 
            else {             
              ul.css({
                "margin-left": "-742px"
              });  
            }
          }       
        }
        else {
          $(".region-header").removeClass("active-region");
        }
      }

      // Add our custom callback to superfish
      $('.sf-main-menu').superfish('option', 'onBeforeShow', handler);
    }
  }
  
  
  
  

  /**
   * Кнопка ПОКАЗАТЬ/СКРЫТЬ элементы на главной странице.
   * Показывает только 9 элементов, остальные скрывает. Их можно развернуть по кнопке
   * @type {{attach: Function}}
   */
  Drupal.behaviors.showHideElementsFront = {
    attach: function(context, settings) {
      var showHideToggleEl = $(context).find('.view:not(.processed-showHideElementsFront) div.show-hide-toggle-wrapper>span>a');
      var view = showHideToggleEl.parents('.view:eq(0)');
      var viewContent = view.find('.view-content');
      view.addClass('.processed-showHideElementsFront');

      function processClick(element) {
        var $this = $(element);

        var target = viewContent.find('.views-row').slice(10); //Все элементы, начиная с девятого
        $this.parent().parent().find('span').hide(); //Скрываем саму кнопку показать/скрыть
        //Если элементов всего было 9 -- то нам больше и делать нечего
        if (target.length > 0) {
          //Hide
          if (!view.hasClass('more-toggle-collapsed')) {
            target.slideUp();
            view.addClass('more-toggle-collapsed').removeClass('more-toggle-expanded');
            $this.parent().parent().find('.state-show').show();
          }
          //Show
          else {
            target.slideDown();
            view.addClass('more-toggle-expanded').removeClass('more-toggle-collapsed');
            $this.parent().parent().find('.state-hide').show();
          }
        }
      }

      showHideToggleEl.bind('click', function() {
        processClick(this);
        return false;
      });

      processClick(showHideToggleEl);
    }
  }

  /**
   * Force all links on dataset search page open in new window
   * @fixme ugly warkaround should be replaced with less ugly one
   */
  Drupal.behaviors.openTitleIntNewWindow = {
    attach: function (context, settings) {
      $('body.section-dataset .view-content .field-name-title a').live('click', function () {
        var win = window.open($(this).attr('href'));
        win.focus();
        return false;
      });
    }
  }

  Drupal.behaviors.superfishMainMenuMod = {
    attach: function(context, settings) {
      var $activeEl = $('.sf-main-menu li.menuparent>a:not(.no-superfish-autoopen)').parent().find('ul a.active');
      if ($activeEl.length > 0) {
        $activeEl.parents('.menuparent:eq(0)').showSuperfishUl();
      }
    }
  }
})(jQuery, Drupal, this, this.document);
