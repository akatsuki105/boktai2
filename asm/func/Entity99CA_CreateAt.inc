	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xda
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019864
	ldr r1, _0801985C @ =Entity99CA_Update
	ldr r2, _08019860 @ =Entity99CA_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity99CA_Init
	cmp r0, #0
	bge _08019864
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019866
	.align 2, 0
_0801985C: .4byte Entity99CA_Update
_08019860: .4byte Entity99CA_Destroy
_08019864:
	adds r0, r4, #0
_08019866:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
