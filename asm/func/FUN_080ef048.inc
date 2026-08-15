	push {r4, r5, r6, lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _080EF14A
	bl FUN_080edda0
	adds r4, r0, #0
	cmp r4, #0
	beq _080EF14A
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080EF14A
	bl VM_GetPC
	cmp r0, #0
	beq _080EF078
	bl Script_GetValue
	b _080EF07A
_080EF078:
	movs r0, #0
_080EF07A:
	strh r0, [r4, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _080EF08A
	bl Script_GetValue
	b _080EF08C
_080EF08A:
	movs r0, #0
_080EF08C:
	strh r0, [r4, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _080EF09C
	bl Script_GetValue
	b _080EF09E
_080EF09C:
	movs r0, #0
_080EF09E:
	strh r0, [r4, #0xc]
	adds r0, r4, #0
	adds r0, #8
	ldrh r1, [r4, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r3, r0, #0
	cmp r2, #0
	blt _080EF0CA
	cmp r1, #0
	blt _080EF0CA
	ldr r0, _080EF0D0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080EF0CA
	ldr r0, _080EF0D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080EF0D8
_080EF0CA:
	movs r1, #0
	b _080EF0E6
	.align 2, 0
_080EF0D0: .4byte 0x030046A8
_080EF0D4: .4byte 0x030046AC
_080EF0D8:
	ldr r0, _080EF100 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_080EF0E6:
	ldr r2, _080EF104 @ =0x00000256
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r5, [r0]
	adds r6, r3, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080EF108
	adds r0, #4
	b _080EF114
	.align 2, 0
_080EF100: .4byte 0x030046A4
_080EF104: .4byte 0x00000256
_080EF108:
	ldr r0, _080EF128 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080EF114:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080EF12C
	cmp r3, #2
	beq _080EF130
	b _080EF134
	.align 2, 0
_080EF128: .4byte 0x030046A4
_080EF12C:
	ldrb r0, [r6, #4]
	b _080EF132
_080EF130:
	ldrb r0, [r6]
_080EF132:
	subs r2, r2, r0
_080EF134:
	ldr r3, _080EF150 @ =0x00000472
	adds r0, r4, r3
	strh r2, [r0]
	ldrh r1, [r4, #0xa]
	subs r1, r1, r2
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r2, r4, r3
	strh r1, [r2]
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
_080EF14A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080EF150: .4byte 0x00000472
