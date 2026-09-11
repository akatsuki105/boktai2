	push {r4, lr}
	adds r4, r0, #0
	movs r1, #4
	ldr r0, _082001E8 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _082001DE
	adds r0, r4, #0
	bl FUN_08022e20
	adds r0, r4, #0
	bl FUN_081ffd9c
	adds r0, r4, #0
	bl FUN_081fc86c
	adds r0, r4, #0
	bl FUN_081ff740
	adds r0, r4, #0
	bl FUN_081ff734
	adds r0, r4, #0
	bl FUN_08022ec0
	adds r0, r4, #0
	bl FUN_081ffdb0
_082001DE:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_082001E8: .4byte 0x03002BC0
