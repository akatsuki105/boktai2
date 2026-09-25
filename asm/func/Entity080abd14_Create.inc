	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0x8e
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080ABD64
	ldr r1, _080ABD5C @ =Entity080abd14_Update
	ldr r2, _080ABD60 @ =Entity080abd14_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity080abd14_Init
	cmp r0, #0
	bge _080ABD64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080ABD66
	.align 2, 0
_080ABD5C: .4byte Entity080abd14_Update
_080ABD60: .4byte Entity080abd14_Destroy
_080ABD64:
	adds r0, r4, #0
_080ABD66:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
