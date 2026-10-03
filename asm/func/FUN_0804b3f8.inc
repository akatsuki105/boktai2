	push {r4, lr}
	adds r4, r0, #0
	movs r1, #3
	bl EntityFB53_SetupBG
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl TextPanel_Create
	str r0, [r4, #0x30]
	adds r0, r4, #0
	bl FUN_0804b2dc
	cmp r0, #0
	blt _0804B448
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #0x18]
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B43E
	ldr r1, [r4, #0x28]
	bl TextPanel_SetScript
	ldr r0, [r4, #0x30]
	movs r1, #2
	bl TextPanel_SetMessage
	ldr r0, [r4, #0x30]
	bl TextPanel_Start
_0804B43E:
	bl rfu_REQ_startSearchParent
	bl rfu_waitREQComplete
	b _0804B46C
_0804B448:
	movs r1, #0
	strb r1, [r4, #0x18]
	movs r0, #1
	strb r0, [r4, #0x19]
	str r1, [r4, #0x24]
	ldr r0, [r4, #0x30]
	cmp r0, #0
	blt _0804B46C
	ldr r1, [r4, #0x28]
	bl TextPanel_SetScript
	ldr r0, [r4, #0x30]
	movs r1, #1
	bl TextPanel_SetMessage
	ldr r0, [r4, #0x30]
	bl TextPanel_Start
_0804B46C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
