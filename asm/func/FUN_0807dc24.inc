	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807DC48 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807DC5A
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0807DC4C
	bl Script_GetValue
	adds r1, r0, #0
	b _0807DC4E
	.align 2, 0
_0807DC48: .4byte 0x03002BE0
_0807DC4C:
	movs r1, #0
_0807DC4E:
	adds r0, r4, #0
	bl FUN_0807cc14
	adds r0, r4, #0
	bl FUN_08072640
_0807DC5A:
	pop {r4}
	pop {r0}
	bx r0
