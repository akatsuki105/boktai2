	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xa1
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AC3C4
	ldr r1, _080AC3BC @ =Entity080ac374_Update
	ldr r2, _080AC3C0 @ =Entity080ac374_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity080ac374_Init
	cmp r0, #0
	bge _080AC3C4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AC3C6
	.align 2, 0
_080AC3BC: .4byte Entity080ac374_Update
_080AC3C0: .4byte Entity080ac374_Destroy
_080AC3C4:
	adds r0, r4, #0
_080AC3C6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
