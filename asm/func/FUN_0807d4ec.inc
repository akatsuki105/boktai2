	push {r4, r5, lr}
	bl FUN_0807afe8
	ldr r1, _0807D528 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0807D55A
	bl FUN_0807d180
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _0807D514
	cmp r0, #5
	bne _0807D53E
_0807D514:
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0807D52C
	bl Script_GetValue
	adds r1, r0, #0
	b _0807D52E
	.align 2, 0
_0807D528: .4byte 0x03002BE0
_0807D52C:
	movs r1, #0
_0807D52E:
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0807bbb0
	adds r0, r4, #0
	bl FUN_08072640
	b _0807D55A
_0807D53E:
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r4, r1
	str r5, [r0]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_0807b910
	adds r0, r4, #0
	bl FUN_08072640
	adds r0, r4, #0
	bl FUN_08072650
_0807D55A:
	pop {r4, r5}
	pop {r0}
	bx r0
