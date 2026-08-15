	push {r4, lr}
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0807B19C
	bl Script_GetValue
	adds r4, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807B19C
	bl Script_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0807a7f8
_0807B19C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
