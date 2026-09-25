	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	cmp r4, #0
	beq _080DD92C
	ldr r0, _080DD938 @ =0x03000170
	ldr r0, [r0]
	cmp r0, #0
	bne _080DD8F4
	bl AttackBoxManager_Create
	cmp r0, #0
	beq _080DD92C
_080DD8F4:
	bl AttackBoxManager_Alloc
	adds r3, r0, #0
	cmp r3, #0
	beq _080DD92C
	adds r1, r3, #0
	adds r1, #0x5d
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x50]
	str r1, [r3, #0x54]
	adds r0, r3, #0
	adds r0, #0x58
	strh r2, [r0]
	adds r0, #4
	strb r5, [r0]
	str r6, [r3, #0x60]
	ldr r0, [sp, #0x20]
	str r0, [sp]
	adds r0, r3, #0
	adds r1, r7, #0
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl AttackBox_Setup
_080DD92C:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DD938: .4byte 0x03000170
