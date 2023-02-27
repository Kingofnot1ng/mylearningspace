import VueRouter from "vue-router"
import Login from './components/Login.vue'
import Register from './components/Register.vue'
var router =new VueRouter({
    mode:'history',
    linkActiveClass:'my-active',
    linkExactActiveClass:'my-exact-active',
    routes:[
        {path:'/',redirect:'/login'},
        {path:'/login',component:Login,meta:{title:'登录'}},
        {path:'/register',component:Register,meta:{title:'注册'}},
    ]
})

router.beforeEach(
    (to,form,next)=>{
        if(to.meta.title){
            document.title=to.meta.title
        }
        next()
    }
);

export default router