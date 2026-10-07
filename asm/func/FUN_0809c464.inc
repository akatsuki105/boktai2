	push {r4, lr}
	ldr r4, _0809C4C0 @ =0x0300013C
	ldr r2, [r4]
	cmp r2, #0
	beq _0809C4E8
	ldr r0, _0809C4C4 @ =0x03002BE0
	ldr r1, [r0]
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r2, r3
	str r1, [r0]
	cmp r1, #0
	beq _0809C4E8
	adds r0, r2, #0
	bl FUN_0808d774
	ldr r0, [r4]
	bl FUN_0808d564
	ldr r0, [r4]
	bl FUN_0808d5cc
	ldr r0, [r4]
	bl FUN_0808d4dc
	ldr r0, _0809C4C8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0809C4D0
	ldr r1, [r4]
	ldr r2, _0809C4CC @ =0x000009FE
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809C4B6
	adds r0, r1, #0
	bl FUN_0808e224
_0809C4B6:
	ldr r0, [r4]
	bl EntityCC28_HideSprites
	b _0809C4E8
	.align 2, 0
_0809C4C0: .4byte 0x0300013C
_0809C4C4: .4byte 0x03002BE0
_0809C4C8: .4byte 0x030047A4
_0809C4CC: .4byte 0x000009FE
_0809C4D0:
	ldr r1, [r4]
	ldr r3, _0809C4F0 @ =0x000009FE
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809C4E8
	adds r0, r1, #0
	bl FUN_0808d3d4
	ldr r0, [r4]
	bl FUN_0808ce98
_0809C4E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C4F0: .4byte 0x000009FE
