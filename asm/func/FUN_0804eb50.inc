	push {r4, lr}
	adds r4, r0, #0
	movs r2, #4
	ldr r1, _0804EBC0 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804EB6C
	movs r0, #0
	strb r0, [r4, #0x19]
	bl FUN_0804e5bc
_0804EB6C:
	ldr r0, [r4, #0x1c]
	cmp r0, #4
	bne _0804EBB4
	movs r0, #1
	bl Sound_FadeOutBGM
	adds r0, r4, #0
	bl FUN_0804ea1c
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0804ea68
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	movs r1, #7
	movs r2, #0x1c
	movs r3, #6
	bl TextPanel_Create
	str r0, [r4, #0x20]
	cmp r0, #0
	blt _0804EBB4
	ldr r1, [r4, #0x28]
	bl TextPanel_SetScript
	ldr r0, [r4, #0x20]
	movs r1, #0
	bl TextPanel_SetMessage
	ldr r0, [r4, #0x20]
	bl TextPanel_Start
_0804EBB4:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804EBC0: .4byte 0x030044BC
