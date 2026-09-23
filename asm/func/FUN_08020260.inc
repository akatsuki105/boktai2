	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r0, _0802030C @ =0x000085E6
	bl FUN_08230e70
	adds r5, r0, #0
	cmp r5, #0
	beq _08020302
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08020302
	bl Script_GetValue
	adds r7, r0, #0
	movs r2, #0
	movs r4, #0
	movs r6, #0
	ldrh r3, [r5, #0x1a]
	cmp r6, r3
	bge _080202A4
	ldr r1, _08020310 @ =0x0000042C
	adds r0, r5, r1
	ldr r1, [r0]
_08020292:
	ldrh r0, [r1, #0x34]
	cmp r0, r7
	bne _0802029C
	adds r4, #1
	adds r6, r2, #0
_0802029C:
	adds r1, #0x8c
	adds r2, #1
	cmp r2, r3
	blt _08020292
_080202A4:
	cmp r4, #0
	beq _08020302
	cmp r4, #1
	bgt _08020302
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08020302
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _08020310 @ =0x0000042C
	adds r5, r5, r0
	ldr r0, [r5]
	movs r1, #0x8c
	adds r4, r6, #0
	muls r4, r1, r4
	adds r0, r4, r0
	movs r1, #0x1c
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldr r0, [r5]
	adds r0, r4, r0
	movs r1, #0x1e
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldr r0, [r5]
	adds r4, r4, r0
	movs r0, #0x20
	ldrsh r2, [r4, r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
_08020302:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802030C: .4byte 0x000085E6
_08020310: .4byte 0x0000042C
