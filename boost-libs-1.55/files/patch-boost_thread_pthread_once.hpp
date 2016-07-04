--- boost/thread/pthread/once.hpp.orig	2013-03-23 01:48:21 UTC
+++ boost/thread/pthread/once.hpp
@@ -42,7 +42,7 @@ namespace boost
   }
 
 #ifdef BOOST_THREAD_PROVIDES_ONCE_CXX11
-#ifndef BOOST_NO_CXX11_VARIADIC_TEMPLATES
+#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES) 
     template<typename Function, class ...ArgTypes>
     inline void call_once(once_flag& flag, BOOST_THREAD_RV_REF(Function) f, BOOST_THREAD_RV_REF(ArgTypes)... args);
 #else
@@ -65,7 +65,7 @@ namespace boost
   private:
       volatile thread_detail::uintmax_atomic_t epoch;
 
-#ifndef BOOST_NO_CXX11_VARIADIC_TEMPLATES
+#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
       template<typename Function, class ...ArgTypes>
       friend void call_once(once_flag& flag, BOOST_THREAD_RV_REF(Function) f, BOOST_THREAD_RV_REF(ArgTypes)... args);
 #else
@@ -118,7 +118,7 @@ namespace boost
     // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2444.html
 
 
-#ifndef BOOST_NO_CXX11_VARIADIC_TEMPLATES
+#if !defined(BOOST_NO_CXX11_VARIADIC_TEMPLATES) && !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
 
 
   template<typename Function, class ...ArgTypes>
