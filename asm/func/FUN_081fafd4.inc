	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081FB048 @ =0x05000002
	bl CpuSet
	movs r0, #0
	mov sl, r0
	add r5, sp, #0x44
	ldr r6, _081FB04C @ =0x030046B8
	ldr r1, _081FB050 @ =0x085AE5FC
	mov sb, r1
	ldr r2, _081FB054 @ =0x000003FF
	mov r8, r2
_081FB000:
	mov r0, sb
	ldrh r1, [r0]
	ldr r0, [sp, #0x44]
	ldr r2, _081FB058 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x44]
	mov r0, sb
	ldrh r1, [r0, #2]
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	mov r1, sl
	cmp r1, #1
	bgt _081FB060
	ldr r0, [r6]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _081FB05C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	bl Mod
	cmp r0, #0
	bge _081FB040
	rsbs r0, r0, #0
_081FB040:
	ldrh r1, [r5]
	adds r1, r1, r0
	b _081FB084
	.align 2, 0
_081FB048: .4byte 0x05000002
_081FB04C: .4byte 0x030046B8
_081FB050: .4byte 0x085AE5FC
_081FB054: .4byte 0x000003FF
_081FB058: .4byte 0xFFFF0000
_081FB05C: .4byte 0x0203B400
_081FB060:
	ldr r0, [r6]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FB0C0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	bl Mod
	cmp r0, #0
	bge _081FB080
	rsbs r0, r0, #0
_081FB080:
	ldrh r1, [r5]
	subs r1, r1, r0
_081FB084:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x44]
	ldr r2, _081FB0C4 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x44]
	adds r7, r5, #0
	add r0, sp, #0x44
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FB0BA
	cmp r1, #0
	blt _081FB0BA
	ldr r0, _081FB0C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FB0BA
	ldr r0, _081FB0CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FB0D0
_081FB0BA:
	movs r4, #0
	b _081FB0DE
	.align 2, 0
_081FB0C0: .4byte 0x0203B400
_081FB0C4: .4byte 0xFFFF0000
_081FB0C8: .4byte 0x030046A8
_081FB0CC: .4byte 0x030046AC
_081FB0D0:
	ldr r0, _081FB0F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FB0DE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FB0F4
	adds r0, #4
	b _081FB100
	.align 2, 0
_081FB0F0: .4byte 0x030046A4
_081FB0F4:
	ldr r0, _081FB12C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FB100:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0
	strh r0, [r7, #2]
	ldr r0, [r6]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FB130 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081FB134
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08204d04
	b _081FB164
	.align 2, 0
_081FB12C: .4byte 0x030046A4
_081FB130: .4byte 0x0203B400
_081FB134:
	movs r0, #3
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FB1A4 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
	str r1, [sp, #0x34]
	adds r0, r5, #0
	add r1, sp, #0x3c
	ldr r2, _081FB1A8 @ =0x00002E78
	ldr r3, _081FB1AC @ =0x000038E2
	bl FUN_081f22c0
_081FB164:
	mov r1, sb
	ldrh r0, [r1]
	strh r0, [r5]
	ldrh r0, [r1, #2]
	add r4, sp, #0x44
	strh r0, [r4, #4]
	mov r2, sl
	cmp r2, #0
	beq _081FB17A
	cmp r2, #3
	bne _081FB1B4
_081FB17A:
	ldr r0, [r6]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FB1B0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	bl Mod
	adds r1, r0, #0
	cmp r1, #0
	bge _081FB19C
	rsbs r1, r1, #0
_081FB19C:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	b _081FB1DA
	.align 2, 0
_081FB1A4: .4byte 0x00000232
_081FB1A8: .4byte 0x00002E78
_081FB1AC: .4byte 0x000038E2
_081FB1B0: .4byte 0x0203B400
_081FB1B4:
	ldr r0, [r6]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FB208 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	bl Mod
	adds r1, r0, #0
	cmp r1, #0
	bge _081FB1D6
	rsbs r1, r1, #0
_081FB1D6:
	ldrh r0, [r4, #4]
	subs r0, r0, r1
_081FB1DA:
	strh r0, [r4, #4]
	adds r7, r5, #0
	add r0, sp, #0x44
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FB204
	cmp r1, #0
	blt _081FB204
	ldr r0, _081FB20C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FB204
	ldr r0, _081FB210 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FB214
_081FB204:
	movs r4, #0
	b _081FB222
	.align 2, 0
_081FB208: .4byte 0x0203B400
_081FB20C: .4byte 0x030046A8
_081FB210: .4byte 0x030046AC
_081FB214:
	ldr r0, _081FB234 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FB222:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FB238
	adds r0, #4
	b _081FB244
	.align 2, 0
_081FB234: .4byte 0x030046A4
_081FB238:
	ldr r0, _081FB270 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FB244:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0
	strh r0, [r7, #2]
	ldr r0, [r6]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FB274 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081FB278
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08204d04
	b _081FB2A8
	.align 2, 0
_081FB270: .4byte 0x030046A4
_081FB274: .4byte 0x0203B400
_081FB278:
	movs r0, #3
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FB2C8 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
	str r1, [sp, #0x34]
	adds r0, r5, #0
	add r1, sp, #0x3c
	ldr r2, _081FB2CC @ =0x00002E78
	ldr r3, _081FB2D0 @ =0x000038E2
	bl FUN_081f22c0
_081FB2A8:
	movs r0, #4
	add sb, r0
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #3
	bgt _081FB2B8
	b _081FB000
_081FB2B8:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FB2C8: .4byte 0x00000232
_081FB2CC: .4byte 0x00002E78
_081FB2D0: .4byte 0x000038E2
