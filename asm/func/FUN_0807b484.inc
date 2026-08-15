	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807B4B4 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807B4AC
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0807B4AC
	bl Script_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08063634
_0807B4AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B4B4: .4byte 0x03002BE0
