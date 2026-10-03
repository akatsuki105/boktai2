	push {lr}
	bl FUN_0823a6c0
	cmp r0, #0
	blt _0804B33C
	ldr r0, _0804B328 @ =EntityFB53_SetLinkError
	bl rfu_setREQCallback
	bl rfu_REQBN_softReset_and_checkID
	ldr r1, _0804B32C @ =0x00008001
	cmp r0, r1
	bne _0804B33C
	bl rfu_REQ_reset
	bl rfu_waitREQComplete
	movs r0, #0
	movs r1, #4
	movs r2, #0x20
	bl rfu_REQ_configSystem
	bl rfu_waitREQComplete
	ldr r2, _0804B330 @ =0x08251D30
	ldr r3, _0804B334 @ =0x08251D38
	movs r0, #0
	movs r1, #0x10
	bl rfu_REQ_configGameData
	bl rfu_waitREQComplete
	ldr r0, _0804B338 @ =EntityFB53_WatchLink
	bl rfu_setMSCCallback
	movs r0, #0
	b _0804B340
	.align 2, 0
_0804B328: .4byte EntityFB53_SetLinkError
_0804B32C: .4byte 0x00008001
_0804B330: .4byte 0x08251D30
_0804B334: .4byte 0x08251D38
_0804B338: .4byte EntityFB53_WatchLink
_0804B33C:
	movs r0, #1
	rsbs r0, r0, #0
_0804B340:
	pop {r1}
	bx r1
