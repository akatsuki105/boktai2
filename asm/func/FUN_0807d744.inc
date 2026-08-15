	push {r4, r5, r6, r7, lr}
	sub sp, #4
	bl FUN_0807afe8
	ldr r1, _0807D76C @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D7A4
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0807D770
	bl Script_GetValue
	adds r7, r0, #0
	b _0807D772
	.align 2, 0
_0807D76C: .4byte 0x03002BE0
_0807D770:
	movs r7, #0x32
_0807D772:
	movs r0, #0x4c
	bl prepare_08231510
	cmp r0, #0
	beq _0807D784
	bl Script_GetValue
	adds r6, r0, #0
	b _0807D786
_0807D784:
	movs r6, #0
_0807D786:
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	adds r3, r6, #0
	bl FUN_0807bfa4
	adds r0, r5, #0
	bl FUN_08072640
_0807D7A4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
