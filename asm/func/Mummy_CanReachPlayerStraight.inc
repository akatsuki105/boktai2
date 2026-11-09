	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #8]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, [r1, #0x18]
	ldrh r0, [r0, #6]
	mov sb, r0
	ldr r2, [sp, #8]
	ldrb r2, [r2, #5]
	str r2, [sp, #0xc]
	mov r2, sp
	ldr r4, [sp, #8]
	adds r4, #8
	adds r3, r1, #0
	adds r3, #8
	ldrh r0, [r1, #8]
	ldr r5, [sp, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r1, _08128170 @ =0x00000256
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp sb, r0
	bne _0812814C
	b _08128294
_0812814C:
	ldr r2, [sp, #8]
	ldr r3, _08128170 @ =0x00000256
	adds r0, r2, r3
	ldrh r6, [r0]
	movs r0, #0xa
	ldrsh r5, [r2, r0]
	mov r8, r5
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08128178
	adds r0, #4
	ldr r1, _08128174 @ =0x030046A4
	mov sl, r1
	b _08128186
	.align 2, 0
_08128170: .4byte 0x00000256
_08128174: .4byte 0x030046A4
_08128178:
	ldr r2, _081281B0 @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
	mov sl, r2
_08128186:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r5, #6
	ldrsh r0, [r0, r5]
	adds r2, r1, #0
	muls r2, r0, r2
	str r2, [sp, #0x10]
	cmp r6, sb
	bge _0812821C
	adds r4, r6, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	b _081281BC
	.align 2, 0
_081281B0: .4byte 0x030046A4
_081281B4:
	cmp r4, sb
	beq _08128218
	adds r4, #1
	adds r5, #1
_081281BC:
	mov r3, sl
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r5, r0
	bge _081281DC
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081281B4
_081281DC:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	adds r4, r6, r0
	b _081281FA
_081281EA:
	cmp r4, sb
	beq _08128218
	ldr r0, _08128214 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r0, [r0, r5]
	adds r4, r4, r0
_081281FA:
	ldr r0, [sp, #0x10]
	cmp r0, r4
	ble _0812827E
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081281EA
	b _0812827E
	.align 2, 0
_08128214: .4byte 0x030046A4
_08128218:
	movs r0, #1
	b _08128280
_0812821C:
	subs r4, r6, #1
	adds r0, r4, #0
	bl Mod
	adds r5, r0, #0
	b _08128230
_08128228:
	cmp r4, sb
	beq _08128218
	subs r4, #1
	subs r5, #1
_08128230:
	cmp r5, #0
	blt _08128246
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08128228
_08128246:
	ldr r0, _08128254 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	b _08128268
	.align 2, 0
_08128254: .4byte 0x030046A4
_08128258:
	cmp r4, sb
	beq _08128218
	ldr r0, _08128290 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r4, r0
_08128268:
	cmp r4, #0
	blt _0812827E
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl CanWalkToAdjacentTile
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08128258
_0812827E:
	movs r0, #0
_08128280:
	cmp r0, #0
	bne _08128294
	mov r3, sp
	ldrb r5, [r3, #0xc]
	ldr r3, [sp, #8]
	strb r5, [r3, #5]
	movs r0, #0
	b _08128296
	.align 2, 0
_08128290: .4byte 0x030046A4
_08128294:
	movs r0, #1
_08128296:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
