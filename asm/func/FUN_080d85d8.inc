	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r0, #0xa
	movs r1, #0xb4
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080D8634
	ldr r1, _080D862C @ =Entity080d84f8_Update
	ldr r2, _080D8630 @ =Entity080d84f8_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #8]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity080d84f8_Init
	cmp r0, #0
	bge _080D8634
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080D8636
	.align 2, 0
_080D862C: .4byte Entity080d84f8_Update
_080D8630: .4byte Entity080d84f8_Destroy
_080D8634:
	adds r0, r4, #0
_080D8636:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
