	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _08229384 @ =0x00000D9C
	adds r0, r6, r1
	bl FUN_0822a4e0
	ldr r1, _08229388 @ =0x00000DF4
	adds r0, r6, r1
	bl FUN_080138fc
	adds r4, r6, #0
	adds r4, #0x1c
	movs r5, #0xf
_0822934E:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0xd8
	subs r5, #1
	cmp r5, #0
	bge _0822934E
	ldr r1, _0822938C @ =0x00000F46
	adds r0, r6, r1
	ldrh r0, [r0]
	bl FUN_0823b2d0
	adds r1, r0, #0
	cmp r1, #0
	beq _08229376
	movs r1, #0xe4
	lsls r1, r1, #4
	adds r0, r6, r1
	bl FUN_0823b284
_08229376:
	ldr r2, _08229390 @ =0x03000248
	movs r1, #0
	str r1, [r2]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08229384: .4byte 0x00000D9C
_08229388: .4byte 0x00000DF4
_0822938C: .4byte 0x00000F46
_08229390: .4byte 0x03000248
