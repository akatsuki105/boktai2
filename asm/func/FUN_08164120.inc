	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _08164170 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08164174 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08164178 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #8]
	strb r0, [r2, #5]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r1, _0816417C @ =0x00000256
	adds r1, r2, r1
	str r1, [sp, #0x14]
	adds r2, #8
	str r2, [sp, #0x18]
	ldr r2, _08164180 @ =0x030046A4
	mov sb, r2
_0816415A:
	ldr r0, [sp, #0x14]
	ldrh r6, [r0]
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08164184
	adds r0, #4
	b _08164190
	.align 2, 0
_08164170: .4byte 0x030046B8
_08164174: .4byte 0x000003FF
_08164178: .4byte 0x0203B400
_0816417C: .4byte 0x00000256
_08164180: .4byte 0x030046A4
_08164184:
	mov r1, sb
	ldr r0, [r1]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08164190:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081641A4
	cmp r3, #2
	beq _081641AA
	b _081641B0
_081641A4:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1, #4]
	b _081641AE
_081641AA:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
_081641AE:
	subs r2, r2, r0
_081641B0:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081641C2
	adds r0, #4
	b _081641CE
_081641C2:
	mov r2, sb
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081641CE:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	ldr r1, [sp, #8]
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _081641E0
	asrs r0, r0, #6
	b _081641E6
_081641E0:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081641E6:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _08164224
	cmp r1, #1
	bgt _081641F8
	cmp r1, #0
	beq _08164202
	b _081642E0
_081641F8:
	cmp r1, #2
	beq _08164264
	cmp r1, #3
	beq _08164286
	b _081642E0
_08164202:
	adds r4, r6, #1
	movs r5, #0
_08164206:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08164220
	adds r4, #1
	adds r5, #1
	cmp r5, #2
	blt _08164206
_08164220:
	subs r5, r4, #1
	b _081642E4
_08164224:
	mov r2, sb
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
	ldr r2, _08164260 @ =0x030046A4
	mov sl, r2
_08164236:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081642C4
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _08164236
	mov r1, sl
	b _081642C6
	.align 2, 0
_08164260: .4byte 0x030046A4
_08164264:
	subs r4, r6, #1
	movs r5, #0
_08164268:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08164282
	subs r4, #1
	adds r5, #1
	cmp r5, #2
	blt _08164268
_08164282:
	adds r5, r4, #1
	b _081642E4
_08164286:
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r6, r0
	movs r5, #0
	ldr r0, _081642C0 @ =0x030046A4
	mov sl, r0
_08164298:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081642D2
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #2
	blt _08164298
	mov r1, sl
	b _081642D4
	.align 2, 0
_081642C0: .4byte 0x030046A4
_081642C4:
	mov r1, sb
_081642C6:
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r4, r0
	b _081642E4
_081642D2:
	mov r1, sb
_081642D4:
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r5, r4, r0
	b _081642E4
_081642E0:
	ldr r0, [sp, #0x14]
	ldrh r5, [r0]
_081642E4:
	ldr r1, [sp, #0x14]
	ldrh r1, [r1]
	cmp r5, r1
	bne _08164300
	ldr r2, [sp, #8]
	ldrb r0, [r2, #5]
	adds r0, #0x40
	strb r0, [r2, #5]
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
	cmp r0, #3
	bgt _08164300
	b _0816415A
_08164300:
	mov r1, sp
	ldrb r2, [r1, #0xc]
	ldr r1, [sp, #8]
	strb r2, [r1, #5]
	mov r8, sp
	ldr r6, _08164344 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08164348
	adds r0, #4
	b _08164352
	.align 2, 0
_08164344: .4byte 0x030046A4
_08164348:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08164352:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r2, [sp, #8]
	ldr r1, _08164384 @ =0x000004A4
	adds r0, r2, r1
	ldr r2, [r0]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08164384: .4byte 0x000004A4
