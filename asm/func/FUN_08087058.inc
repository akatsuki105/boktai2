	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _08087090
	bl VM_GetValue
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	b _080870A4
_08087090:
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_080870A4:
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080870CE
	cmp r1, #0
	blt _080870CE
	ldr r0, _080870D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080870CE
	ldr r0, _080870D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080870DC
_080870CE:
	movs r4, #0
	b _080870EA
	.align 2, 0
_080870D4: .4byte 0x030046A8
_080870D8: .4byte 0x030046AC
_080870DC:
	ldr r0, _080870FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080870EA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08087100
	adds r0, #4
	b _0808710C
	.align 2, 0
_080870FC: .4byte 0x030046A4
_08087100:
	ldr r0, _08087120 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808710C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087124
	cmp r2, #2
	beq _08087128
	b _0808712C
	.align 2, 0
_08087120: .4byte 0x030046A4
_08087124:
	ldrb r0, [r6, #4]
	b _0808712A
_08087128:
	ldrb r0, [r6]
_0808712A:
	subs r1, r1, r0
_0808712C:
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, r5, #0
	adds r3, #0xa0
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r3, r5, r1
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r3, r5, r0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	adds r4, r5, #0
	adds r4, #0x40
	ldrh r1, [r5, #0x18]
	movs r0, #6
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl Mover_Init
	adds r1, r5, #0
	adds r1, #0x84
	adds r0, r4, #0
	bl Mover_SetAuxSprite
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r1, r5, #0
	adds r1, #0x45
	strb r0, [r1]
	ldrh r1, [r4]
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldrb r0, [r5, #0x1a]
	cmp r0, #3
	beq _080871D4
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	bne _080871BC
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #1
	bl EnemyTargetManager_Add
	b _080871CA
_080871BC:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r4, #0
	movs r2, #4
	bl EnemyTargetManager_Add
_080871CA:
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080871D4:
	adds r0, r4, #0
	bl FUN_08002a48
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
