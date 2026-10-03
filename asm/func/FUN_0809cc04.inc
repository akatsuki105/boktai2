	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808dda4
	adds r0, r4, #0
	bl FUN_0808cf50
	adds r0, r4, #0
	bl FUN_0808cacc
	adds r0, r4, #0
	bl FUN_0809b430
	adds r0, r4, #0
	bl FUN_0808cffc
	ldr r1, _0809CC3C @ =0x03002C14
	ldr r0, _0809CC40 @ =0x00000F56
	adds r4, r4, r0
	ldrb r0, [r4]
	strh r0, [r1]
	ldr r1, _0809CC44 @ =0x0300013C
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809CC3C: .4byte 0x03002C14
_0809CC40: .4byte 0x00000F56
_0809CC44: .4byte 0x0300013C
