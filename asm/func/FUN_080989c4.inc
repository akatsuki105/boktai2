	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08098A84 @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, _08098A88 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	adds r0, r4, #0
	bl FUN_080987a4
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #9
	bl FUN_0808a3c4
	adds r0, r4, #0
	movs r1, #5
	movs r2, #3
	bl FUN_0808b604
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08098A2A
	movs r0, #8
	movs r1, #9
	movs r2, #5
	movs r3, #6
	bl FUN_0808b9c4
_08098A2A:
	adds r0, r4, #0
	bl FUN_0809895c
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _08098A8C @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0809889c
	adds r0, r4, #0
	bl FUN_0809877c
	bl FUN_08049f5c
	ldr r0, _08098A90 @ =0x0000EFDA
	bl TextBox_SetBgPltt
	adds r0, r4, #0
	bl FUN_08097c04
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808c61c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08097fb4
	ldr r1, _08098A94 @ =FUN_08098290
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08098A84: .4byte 0x00004014
_08098A88: .4byte 0x00004018
_08098A8C: .4byte 0x00000F56
_08098A90: .4byte 0x0000EFDA
_08098A94: .4byte FUN_08098290
