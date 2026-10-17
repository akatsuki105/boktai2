	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _080A5904 @ =0x03002C48
	ldr r0, [r0]
	cmp r0, #0
	bne _080A594A
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5908
	bl VM_GetValue
	adds r5, r0, #0
	b _080A590A
	.align 2, 0
_080A5904: .4byte 0x03002C48
_080A5908:
	movs r5, #1
_080A590A:
	movs r0, #0xb8
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, #0x1c
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5948
	ldr r1, _080A5940 @ =Entity3117_Update
	ldr r2, _080A5944 @ =Entity3117_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r5, #0
	bl Entity3117_Init
	cmp r0, #0
	bge _080A5948
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A594A
	.align 2, 0
_080A5940: .4byte Entity3117_Update
_080A5944: .4byte Entity3117_Destroy
_080A5948:
	adds r0, r4, #0
_080A594A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
