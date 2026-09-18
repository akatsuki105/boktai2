	push {r4, lr}
	adds r4, r0, #0
	bl Sound_StopAll
	movs r0, #2
	bl PlaySound_082406e0
	movs r0, #0x96
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, _080A713C @ =0x0000033E
	adds r1, r4, r0
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080A7140 @ =0x00000341
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A713C: .4byte 0x0000033E
_080A7140: .4byte 0x00000341
