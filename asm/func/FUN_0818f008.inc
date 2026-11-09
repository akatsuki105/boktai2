	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r1, #0
	str r1, [sp]
	ldr r2, _0818F04C @ =0x00000F36
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	blt _0818F02C
	b _0818F148
_0818F02C:
	movs r2, #0
	mov sl, r2
	ldr r0, _0818F050 @ =0x00000674
	adds r6, r7, r0
	ldr r1, _0818F054 @ =0x0000077A
	adds r1, r1, r7
	mov sb, r1
_0818F03A:
	movs r1, #1
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0818F058
	movs r0, #1
	b _0818F05A
	.align 2, 0
_0818F04C: .4byte 0x00000F36
_0818F050: .4byte 0x00000674
_0818F054: .4byte 0x0000077A
_0818F058:
	movs r0, #0
_0818F05A:
	cmp r0, #0
	bne _0818F128
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0818F082
	cmp r1, #0
	blt _0818F082
	ldr r0, _0818F088 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0818F082
	ldr r0, _0818F08C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0818F090
_0818F082:
	movs r4, #0
	b _0818F09E
	.align 2, 0
_0818F088: .4byte 0x030046A8
_0818F08C: .4byte 0x030046AC
_0818F090:
	ldr r0, _0818F0B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0818F09E:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0818F0B4
	adds r0, #4
	b _0818F0C0
	.align 2, 0
_0818F0B0: .4byte 0x030046A4
_0818F0B4:
	ldr r0, _0818F0D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0818F0C0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0818F0D8
	cmp r2, #2
	beq _0818F0DC
	b _0818F0E0
	.align 2, 0
_0818F0D4: .4byte 0x030046A4
_0818F0D8:
	ldrb r0, [r5, #4]
	b _0818F0DE
_0818F0DC:
	ldrb r0, [r5]
_0818F0DE:
	subs r1, r1, r0
_0818F0E0:
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, r1
	bge _0818F108
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r1, sl
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	bne _0818F102
	orrs r1, r3
	str r1, [r2]
_0818F102:
	movs r2, #1
	rsbs r2, r2, #0
	b _0818F126
_0818F108:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r1, sl
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0818F124
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
_0818F124:
	movs r2, #1
_0818F126:
	add r8, r2
_0818F128:
	movs r0, #0x92
	lsls r0, r0, #1
	add sl, r0
	adds r6, r6, r0
	add sb, r0
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	ldr r2, _0818F158 @ =0x00000F36
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp]
	cmp r2, r0
	bge _0818F148
	b _0818F03A
_0818F148:
	ldr r1, _0818F158 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	blt _0818F15C
	movs r0, #1
	b _0818F16A
	.align 2, 0
_0818F158: .4byte 0x00000F36
_0818F15C:
	mov r1, r8
	cmn r1, r0
	ble _0818F166
	movs r0, #0
	b _0818F16A
_0818F166:
	movs r0, #1
	rsbs r0, r0, #0
_0818F16A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
