	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808cf50
	adds r0, r4, #0
	bl FUN_0808cffc
	ldr r1, _0809C954 @ =0x00000C0C
	adds r0, r4, r1
	bl MainSprite_Remove
	ldr r0, _0809C958 @ =0x00000DA4
	adds r4, r4, r0
	adds r0, r4, #0
	bl MainSprite_Remove
	ldr r1, _0809C95C @ =0x0300013C
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809C954: .4byte 0x00000C0C
_0809C958: .4byte 0x00000DA4
_0809C95C: .4byte 0x0300013C
