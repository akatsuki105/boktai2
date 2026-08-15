	push {r4, r5, r6, lr}
	bl FUN_0807afe8
	ldr r1, _0807D690 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D6A0
	bl FUN_0807d164
	adds r5, r0, #0
	bl FUN_0807d180
	adds r6, r0, #0
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0807D694
	bl Script_GetValue
	adds r2, r0, #0
	b _0807D696
	.align 2, 0
_0807D690: .4byte 0x03002BE0
_0807D694:
	movs r2, #0
_0807D696:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r3, r6, #0
	bl FUN_0807bdc8
_0807D6A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
