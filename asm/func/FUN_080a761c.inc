	push {r4, lr}
	sub sp, #0xc
	ldr r0, _080A7670 @ =0x03000150
	ldr r4, [r0]
	cmp r4, #0
	beq _080A7668
	adds r0, r4, #0
	bl FUN_080a7410
	movs r0, #7
	bl FUN_0809c08c
	movs r1, #0xd0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A7668
	bl Script_GetValue
	cmp r0, #0
	beq _080A7668
	movs r0, #4
	str r0, [sp]
	ldr r0, _080A7674 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080A7668:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7670: .4byte 0x03000150
_080A7674: .4byte 0x00001FFF
