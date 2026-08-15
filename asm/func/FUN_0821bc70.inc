	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	str r5, [r4, #0x18]
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r4, #0x50]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r4, #0x54]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0821BCA8
	bl Script_GetValue
	str r0, [r4, #0x58]
	bl Script_GetValue
	str r0, [r4, #0x5c]
	bl Script_GetValue
	str r0, [r4, #0x60]
_0821BCA8:
	movs r0, #0x6c
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r4, #0x64]
	movs r0, #0
	str r0, [r4, #0x68]
	str r0, [r4, #0x7c]
	str r0, [r4, #0x6c]
	str r0, [r4, #0x70]
	movs r0, #1
	str r0, [r4, #0x78]
	adds r0, r4, #0
	adds r0, #0x1c
	adds r1, r5, #0
	movs r2, #0xa
	bl FUN_080223f4
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
