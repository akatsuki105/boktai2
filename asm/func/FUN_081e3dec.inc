	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xb0
	lsls r0, r0, #5
	adds r5, r4, r0
	ldr r0, [r5]
	bl TextPanel_Hide
	ldr r1, _081E3E6C @ =0x00001604
	adds r6, r4, r1
	ldr r0, [r6]
	bl TextPanel_Hide
	ldr r0, _081E3E70 @ =0x00001608
	adds r0, r0, r4
	mov r8, r0
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, _081E3E74 @ =0x0000160C
	adds r4, r4, r1
	ldr r0, [r4]
	bl TextPanel_Hide
	ldr r0, [r5]
	movs r5, #2
	str r5, [sp]
	movs r1, #1
	movs r2, #4
	movs r3, #0xa
	bl TextPanel_SetRect
	ldr r0, [r6]
	str r5, [sp]
	movs r1, #0x11
	movs r2, #4
	movs r3, #0xa
	bl TextPanel_SetRect
	mov r1, r8
	ldr r0, [r1]
	str r5, [sp]
	movs r1, #2
	movs r2, #0x10
	movs r3, #0x1c
	bl TextPanel_SetRect
	ldr r0, [r4]
	str r5, [sp]
	movs r1, #0
	movs r2, #0x10
	movs r3, #0x1c
	bl TextPanel_SetRect
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E3E6C: .4byte 0x00001604
_081E3E70: .4byte 0x00001608
_081E3E74: .4byte 0x0000160C
