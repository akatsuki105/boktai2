	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dd9d4
	adds r0, r4, #0
	bl FUN_081ddab4
	adds r1, r0, #0
	cmp r1, #0
	bge _081DF3B8
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF3E4
_081DF3B8:
	ldr r1, [r4, #0x34]
	cmp r1, #0x77
	bls _081DF3E4
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081dded4
	movs r1, #0xdd
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	strh r0, [r4, #0x38]
	adds r0, r4, #0
	bl FUN_081ddf44
	ldr r2, _081DF3EC @ =FUN_081deaf4
	adds r0, r4, #0
	movs r1, #0xa
	bl Entity9A9F_SetState
_081DF3E4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DF3EC: .4byte FUN_081deaf4
