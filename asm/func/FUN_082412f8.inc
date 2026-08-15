	push {r4, lr}
	ldr r0, _0824131C @ =gSystemSaveData
	ldr r0, [r0]
	ldrb r4, [r0, #8]
	adds r0, r4, #0
	bl FUN_082411ac
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241320
	adds r0, r4, #0
	bl FUN_08241260
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241320
	movs r0, #1
	b _08241322
	.align 2, 0
_0824131C: .4byte gSystemSaveData
_08241320:
	movs r0, #0
_08241322:
	pop {r4}
	pop {r1}
	bx r1
