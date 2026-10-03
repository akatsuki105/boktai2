	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl TextBox_Close
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r1, _0809A30C @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, _0809A310 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
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
	movs r3, #0xb
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _0809A314 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, [r4, #0x58]
	bl TextBox_Start
	ldr r0, _0809A318 @ =0x0000EFDA
	bl TextBox_SetBgPltt
	movs r0, #0x11
	bl FUN_08099b3c
	ldr r0, _0809A31C @ =0x0000400C
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c61c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A320 @ =FUN_0809a130
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A30C: .4byte 0x00004014
_0809A310: .4byte 0x00004018
_0809A314: .4byte 0x00000F56
_0809A318: .4byte 0x0000EFDA
_0809A31C: .4byte 0x0000400C
_0809A320: .4byte FUN_0809a130
