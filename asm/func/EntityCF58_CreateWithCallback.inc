	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	ldr r0, _080A61CC @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A61DA
	movs r0, #4
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A61D8
	ldr r1, _080A61D0 @ =EntityCF58_Update
	ldr r2, _080A61D4 @ =EntityCF58_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl EntityCF58_InitWithCallback
	cmp r0, #0
	bge _080A61D8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A61DA
	.align 2, 0
_080A61CC: .4byte 0x0300014C
_080A61D0: .4byte EntityCF58_Update
_080A61D4: .4byte EntityCF58_Destroy
_080A61D8:
	adds r0, r4, #0
_080A61DA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
