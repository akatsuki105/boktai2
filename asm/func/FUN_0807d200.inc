	push {r4, lr}
	bl FUN_0807afe8
	ldr r1, _0807D238 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D232
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807D232
	bl Script_GetValue
	adds r1, r0, #0
	ldr r0, _0807D23C @ =0x00000121
	adds r1, r1, r0
	adds r0, r4, #0
	bl FUN_0807b8a8
	adds r0, r4, #0
	bl FUN_08072640
_0807D232:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807D238: .4byte 0x03002BE0
_0807D23C: .4byte 0x00000121
