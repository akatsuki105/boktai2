	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10c
	adds r7, r0, #0
	movs r0, #0xfd
	bl PlaySound_082406e0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldr r1, [r5]
	ands r1, r0
	str r1, [r5]
	movs r1, #0x10
	mov r8, r1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r6, r7, r2
	ldrh r2, [r6]
	adds r1, r2, #0
	adds r0, r1, #0
	mov r3, r8
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0812A900
	ldr r5, [r7, #0x24]
	ldr r2, _0812A8E0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0812A8E4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _0812A8E8 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	asrs r0, r0, #3
	ldr r1, [r5, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r5, #2]
	cmp r0, r1
	bne _0812A860
	adds r0, #1
	ldr r1, [r5, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0812A860:
	movs r4, #0
	strb r0, [r5, #2]
	strb r4, [r5, #3]
	ldr r0, _0812A8EC @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, [r5, #4]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrb r0, [r5, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r5, #8]
	adds r0, r7, #0
	bl Enemy_StepTowardPathNode
	movs r1, #8
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0812A8F0 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	ldr r5, _0812A8F4 @ =0x0000046A
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0812A8F8 @ =0x00000484
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r7, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb5
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r2, #0x13
	adds r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0812A8FC @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	bl _0812C008
	.align 2, 0
_0812A8E0: .4byte 0x030046B8
_0812A8E4: .4byte 0x000003FF
_0812A8E8: .4byte 0x0203B400
_0812A8EC: .4byte 0x030046A4
_0812A8F0: .4byte 0x00000469
_0812A8F4: .4byte 0x0000046A
_0812A8F8: .4byte 0x00000484
_0812A8FC: .4byte 0x0000046B
_0812A900:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r0, r1
	cmp r0, #0
	bne _0812A90C
	b _0812B074
_0812A90C:
	ldr r3, _0812A994 @ =0x000001DD
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r7, #5]
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	ldr r0, _0812A998 @ =0xFFFFDFDF
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r5, _0812A99C @ =0x00000544
	adds r1, r7, r5
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	mov r2, r8
	orrs r0, r2
	str r0, [r1]
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, _0812A9A0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r3, r7, r3
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xdc]
	str r2, [sp, #0xf0]
	cmp r5, #0
	blt _0812A98E
	cmp r1, #0
	blt _0812A98E
	ldr r0, _0812A9A4 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0812A98E
	ldr r0, _0812A9A8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812A9AC
_0812A98E:
	movs r4, #0
	b _0812A9BA
	.align 2, 0
_0812A994: .4byte 0x000001DD
_0812A998: .4byte 0xFFFFDFDF
_0812A99C: .4byte 0x00000544
_0812A9A0: .4byte 0x03002BE0
_0812A9A4: .4byte 0x030046A8
_0812A9A8: .4byte 0x030046AC
_0812A9AC:
	ldr r0, _0812A9CC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0812A9BA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812A9D0
	adds r0, #4
	b _0812A9DC
	.align 2, 0
_0812A9CC: .4byte 0x030046A4
_0812A9D0:
	ldr r0, _0812A9F0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812A9DC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812A9F4
	cmp r2, #2
	beq _0812A9F8
	b _0812A9FC
	.align 2, 0
_0812A9F0: .4byte 0x030046A4
_0812A9F4:
	ldrb r0, [r6, #4]
	b _0812A9FA
_0812A9F8:
	ldrb r0, [r6]
_0812A9FA:
	subs r1, r1, r0
_0812A9FC:
	strh r1, [r6, #2]
	ldr r0, _0812AA10 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812AA14
	movs r0, #1
	b _0812AA16
	.align 2, 0
_0812AA10: .4byte 0x030047A4
_0812AA14:
	movs r0, #0
_0812AA16:
	cmp r0, #0
	beq _0812AA54
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _0812AA36
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0812AA32
	adds r2, r0, #0
_0812AA32:
	cmp r2, #0
	bge _0812AA40
_0812AA36:
	ldr r6, _0812AA3C @ =0x000005C4
	adds r0, r7, r6
	b _0812AF78
	.align 2, 0
_0812AA3C: .4byte 0x000005C4
_0812AA40:
	ldr r1, _0812AA50 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0812AA9C
	.align 2, 0
_0812AA50: .4byte 0x03002BE0
_0812AA54:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812AA80
	cmp r1, #0
	blt _0812AA80
	ldr r0, _0812AA84 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812AA80
	ldr r0, _0812AA88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812AA8C
_0812AA80:
	movs r5, #0
	b _0812AA9A
	.align 2, 0
_0812AA84: .4byte 0x030046A8
_0812AA88: .4byte 0x030046AC
_0812AA8C:
	ldr r0, _0812AADC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812AA9A:
	movs r2, #0
_0812AA9C:
	ldr r3, _0812AAE0 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _0812AABC
	ldr r1, _0812AAE4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0812AABC
	b _0812AEBC
_0812AABC:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x18]
	str r2, [sp, #0xfc]
	cmp r1, #0
	beq _0812AAE8
	movs r0, #0
	b _0812AF8E
	.align 2, 0
_0812AADC: .4byte 0x030046A4
_0812AAE0: .4byte 0x00000256
_0812AAE4: .4byte 0x03002BE0
_0812AAE8:
	ldr r5, _0812AB8C @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0xfc]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0x104]
	cmp r6, #0
	beq _0812ABAC
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0812AB90 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	movs r5, #1
	strb r5, [r2]
	ldr r3, _0812AB94 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x20]
	movs r4, #0
	strb r4, [r3]
	ldr r6, _0812AB98 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x28]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x2c]
	mov r2, sp
	ldrh r2, [r2, #0x18]
	strh r2, [r1]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _0812AB9C @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _0812ABA0 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0812ABA4 @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x18]
	str r6, [r1]
	ldr r6, _0812ABA8 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xc4]
	str r2, [sp, #0xc8]
	str r1, [sp, #0xd8]
	str r0, [sp, #0xd0]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0xd4]
	ldr r1, [sp, #0x20]
	str r1, [sp, #0xcc]
	ldr r2, [sp, #0x24]
	str r2, [sp, #0xec]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0xf4]
	ldr r4, [sp, #0x2c]
	str r4, [sp, #0x100]
	b _0812AD7A
	.align 2, 0
_0812AB8C: .4byte 0x00000222
_0812AB90: .4byte 0x0000046D
_0812AB94: .4byte 0x0000046B
_0812AB98: .4byte 0x00000553
_0812AB9C: .4byte 0x00000469
_0812ABA0: .4byte 0x0000046A
_0812ABA4: .4byte 0x00000484
_0812ABA8: .4byte 0x0000046C
_0812ABAC:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0812AC70 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x30]
	strb r0, [r2]
	ldr r3, _0812AC74 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x34]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x4d
	adds r5, r7, r5
	str r5, [sp, #0x38]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x3c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x40]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x44]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0812AC78 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0812AC7C @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0812AC80 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xdc]
	ldr r0, [r0]
	str r0, [sp, #0x48]
	ldr r1, [sp, #0xf0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x48]
	strh r1, [r6]
	ldr r6, [sp, #0xf0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x48]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x44]
	str r0, [sp, #0xc0]
	str r5, [sp, #0xc4]
	str r4, [sp, #0xc8]
	str r3, [sp, #0xd8]
	str r2, [sp, #0xd0]
	ldr r2, [sp, #0x30]
	str r2, [sp, #0xd4]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0xcc]
	ldr r4, [sp, #0x38]
	str r4, [sp, #0xec]
	ldr r5, [sp, #0x3c]
	str r5, [sp, #0xf4]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0x100]
	mov r0, sl
	cmp r0, #0
	blt _0812AC6A
	cmp r1, #0
	blt _0812AC6A
	ldr r0, _0812AC84 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _0812AC6A
	ldr r0, _0812AC88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812AC8C
_0812AC6A:
	movs r4, #0
	b _0812AC9C
	.align 2, 0
_0812AC70: .4byte 0x0000046D
_0812AC74: .4byte 0x0000046B
_0812AC78: .4byte 0x00000469
_0812AC7C: .4byte 0x00000484
_0812AC80: .4byte 0x0000046C
_0812AC84: .4byte 0x030046A8
_0812AC88: .4byte 0x030046AC
_0812AC8C:
	ldr r0, _0812ACAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_0812AC9C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812ACB0
	adds r0, #4
	b _0812ACBC
	.align 2, 0
_0812ACAC: .4byte 0x030046A4
_0812ACB0:
	ldr r0, _0812ACD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812ACBC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812ACD4
	cmp r2, #2
	beq _0812ACDA
	b _0812ACE0
	.align 2, 0
_0812ACD0: .4byte 0x030046A4
_0812ACD4:
	ldr r2, [sp, #0x48]
	ldrb r0, [r2, #4]
	b _0812ACDE
_0812ACDA:
	ldr r3, [sp, #0x48]
	ldrb r0, [r3]
_0812ACDE:
	subs r1, r1, r0
_0812ACE0:
	ldr r4, [sp, #0x48]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xdc]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812AD0C
	cmp r1, #0
	blt _0812AD0C
	ldr r0, _0812AD10 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812AD0C
	ldr r0, _0812AD14 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812AD18
_0812AD0C:
	movs r4, #0
	b _0812AD26
	.align 2, 0
_0812AD10: .4byte 0x030046A8
_0812AD14: .4byte 0x030046AC
_0812AD18:
	ldr r0, _0812AD3C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812AD26:
	ldr r6, [sp, #0xdc]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812AD40
	adds r0, #4
	b _0812AD4C
	.align 2, 0
_0812AD3C: .4byte 0x030046A4
_0812AD40:
	ldr r0, _0812AD60 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812AD4C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0812AD64
	cmp r3, #2
	beq _0812AD68
	b _0812AD6C
	.align 2, 0
_0812AD60: .4byte 0x030046A4
_0812AD64:
	ldrb r0, [r5, #4]
	b _0812AD6A
_0812AD68:
	ldrb r0, [r5]
_0812AD6A:
	subs r2, r2, r0
_0812AD6C:
	ldr r1, [sp, #0xdc]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xdc]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0812AD7A:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x4c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xfc]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _0812ADA4 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _0812AE84
	movs r1, #4
	ldr r2, [sp, #0x104]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0812ADA8
	movs r0, #1
	b _0812ADAA
	.align 2, 0
_0812ADA4: .4byte 0x00000482
_0812ADA8:
	movs r0, #0
_0812ADAA:
	ldr r3, _0812AE94 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _0812AE84
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0812AE98 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0812AE9C @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0812AEA0 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	ldr r0, _0812AEA4 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xe0]
	ldr r1, _0812AEA8 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _0812AEAC @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r1, _0812AEB0 @ =0x030046B8
	str r4, [sp, #0x108]
_0812ADF0:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0812AEB4 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0812AEB8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x108]
	cmp r0, r2
	bne _0812AE16
	adds r3, #1
	cmp r3, #3
	ble _0812ADF0
	adds r0, r4, #0
_0812AE16:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xf4]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xec]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xc4]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc8]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe8]
	strb r0, [r6]
	add r0, sp, #0x4c
	ldrb r1, [r0]
	ldr r0, [sp, #0xe0]
	strb r1, [r0]
	ldr r1, [sp, #0xf8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xd4]
	strb r1, [r4]
	ldr r6, [sp, #0xcc]
	strb r3, [r6]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r6, [sp, #0xf4]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x100]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xc0]
	strb r0, [r4]
	ldr r6, [sp, #0xc4]
	strb r1, [r6]
	ldr r0, [sp, #0xc8]
	strb r2, [r0]
	ldr r2, [sp, #0xd8]
	str r3, [r2]
	ldr r3, [sp, #0xd0]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
_0812AE84:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _0812AF8E
	.align 2, 0
_0812AE94: .4byte 0x00000482
_0812AE98: .4byte 0x0000054F
_0812AE9C: .4byte 0x0000054D
_0812AEA0: .4byte 0x0000054E
_0812AEA4: .4byte 0x00000541
_0812AEA8: .4byte 0x000005BC
_0812AEAC: .4byte 0x00000542
_0812AEB0: .4byte 0x030046B8
_0812AEB4: .4byte 0x000003FF
_0812AEB8: .4byte 0x0203B400
_0812AEBC:
	mov sb, sp
	ldr r6, _0812AEF8 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812AEFC
	adds r0, #4
	b _0812AF06
	.align 2, 0
_0812AEF8: .4byte 0x030046A4
_0812AEFC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812AF06:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0812AF3C @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0812AF40
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0812AF66
	.align 2, 0
_0812AF3C: .4byte 0x000004A4
_0812AF40:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0812AF60
	cmp r0, #2
	beq _0812AF5C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812AF5C:
	movs r0, #1
	b _0812AF70
_0812AF60:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0812AF66:
	ldr r1, _0812AF84 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812AF70:
	cmp r0, #0
	bne _0812AF8C
	ldr r3, _0812AF88 @ =0x000005C4
	adds r0, r7, r3
_0812AF78:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0812AF8E
	.align 2, 0
_0812AF84: .4byte 0xFFFFFDFF
_0812AF88: .4byte 0x000005C4
_0812AF8C:
	movs r0, #1
_0812AF8E:
	cmp r0, #0
	bne _0812B008
	ldr r4, _0812AFC0 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0812AFC4
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0812AFEA
	.align 2, 0
_0812AFC0: .4byte 0x000004A4
_0812AFC4:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0812AFE4
	cmp r0, #2
	beq _0812AFE0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812AFE0:
	movs r0, #1
	b _0812AFF4
_0812AFE4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0812AFEA:
	ldr r1, _0812B000 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812AFF4:
	cmp r0, #0
	bne _0812B008
	ldr r4, _0812B004 @ =0x000005C4
	adds r0, r7, r4
	bl FUN_0812bf9c
	.align 2, 0
_0812B000: .4byte 0xFFFFFDFF
_0812B004: .4byte 0x000005C4
_0812B008:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0812B060 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0812B064 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0812B068 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0812B06C @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0812B070 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	bl FUN_0812c004
	.align 2, 0
_0812B060: .4byte 0x0000046D
_0812B064: .4byte 0x0000046B
_0812B068: .4byte 0x00000469
_0812B06C: .4byte 0x0000046A
_0812B070: .4byte 0x00000484
_0812B074:
	ldr r4, _0812B08C @ =0x00008002
	ands r4, r1
	cmp r4, #0
	beq _0812B090
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	strh r0, [r6]
_0812B084:
	movs r0, #0
	bl FUN_0812c00a
	.align 2, 0
_0812B08C: .4byte 0x00008002
_0812B090:
	ldr r1, _0812B0FC @ =0x0000049C
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _0812B118
	ldr r2, _0812B100 @ =0x000005CC
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #0x12
	ldr r3, _0812B104 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0812B108 @ =0x0000046B
	adds r0, r7, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0812B10C @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _0812B110 @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	ldr r1, _0812B114 @ =0xFEFFFFFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	bl _0812C008
	.align 2, 0
_0812B0FC: .4byte 0x0000049C
_0812B100: .4byte 0x000005CC
_0812B104: .4byte 0x0000046D
_0812B108: .4byte 0x0000046B
_0812B10C: .4byte 0x00000469
_0812B110: .4byte 0x0000046C
_0812B114: .4byte 0xFEFFFFFF
_0812B118:
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	strh r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0812B084
	ldr r3, _0812B1DC @ =0x000004BE
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _0812B084
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0812B13E
	b _0812B89C
_0812B13E:
	ldr r4, _0812B1E0 @ =0x0000048D
	adds r2, r7, r4
	ldrb r0, [r2]
	cmp r0, #0
	bne _0812B16A
	ldr r5, _0812B1E4 @ =0x0000048C
	adds r0, r7, r5
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0812B16A
	ldr r6, _0812B1DC @ =0x000004BE
	adds r0, r7, r6
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_0812B16A:
	movs r0, #0xec
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r0, [r4]
	cmp r0, #0
	beq _0812B084
	movs r2, #0x80
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r5, _0812B1E8 @ =0x00000222
	adds r3, r7, r5
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r0, _0812B1EC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r4]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r4, r7, r6
	ldr r6, [r4]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xdc]
	str r2, [sp, #0xf0]
	str r3, [sp, #0x104]
	cmp r5, #0
	blt _0812B1D6
	cmp r1, #0
	blt _0812B1D6
	ldr r0, _0812B1F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0812B1D6
	ldr r0, _0812B1F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812B1F8
_0812B1D6:
	movs r4, #0
	b _0812B206
	.align 2, 0
_0812B1DC: .4byte 0x000004BE
_0812B1E0: .4byte 0x0000048D
_0812B1E4: .4byte 0x0000048C
_0812B1E8: .4byte 0x00000222
_0812B1EC: .4byte 0x03002BE0
_0812B1F0: .4byte 0x030046A8
_0812B1F4: .4byte 0x030046AC
_0812B1F8:
	ldr r0, _0812B218 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0812B206:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812B21C
	adds r0, #4
	b _0812B228
	.align 2, 0
_0812B218: .4byte 0x030046A4
_0812B21C:
	ldr r0, _0812B23C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812B228:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812B240
	cmp r2, #2
	beq _0812B244
	b _0812B248
	.align 2, 0
_0812B23C: .4byte 0x030046A4
_0812B240:
	ldrb r0, [r6, #4]
	b _0812B246
_0812B244:
	ldrb r0, [r6]
_0812B246:
	subs r1, r1, r0
_0812B248:
	strh r1, [r6, #2]
	ldr r0, _0812B25C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812B260
	movs r0, #1
	b _0812B262
	.align 2, 0
_0812B25C: .4byte 0x030047A4
_0812B260:
	movs r0, #0
_0812B262:
	cmp r0, #0
	beq _0812B298
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0812B274
	b _0812B7A8
_0812B274:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0812B280
	adds r2, r0, #0
_0812B280:
	cmp r2, #0
	bge _0812B286
	b _0812B7A8
_0812B286:
	ldr r1, _0812B294 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0812B2E0
	.align 2, 0
_0812B294: .4byte 0x03002BE0
_0812B298:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812B2C4
	cmp r1, #0
	blt _0812B2C4
	ldr r0, _0812B2C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812B2C4
	ldr r0, _0812B2CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812B2D0
_0812B2C4:
	movs r5, #0
	b _0812B2DE
	.align 2, 0
_0812B2C8: .4byte 0x030046A8
_0812B2CC: .4byte 0x030046AC
_0812B2D0:
	ldr r0, _0812B320 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812B2DE:
	movs r2, #0
_0812B2E0:
	ldr r4, _0812B324 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0812B300
	ldr r1, _0812B328 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0812B300
	b _0812B6EC
_0812B300:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x50]
	str r2, [sp, #0xfc]
	cmp r1, #0
	beq _0812B32C
	movs r0, #0
	b _0812B7C2
	.align 2, 0
_0812B320: .4byte 0x030046A4
_0812B324: .4byte 0x00000256
_0812B328: .4byte 0x03002BE0
_0812B32C:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r6, [sp, #0x104]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0x80
	ldr r2, [sp, #0xfc]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0812B3DC
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r4, _0812B3CC @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x54]
	movs r5, #1
	strb r5, [r4]
	ldr r6, _0812B3D0 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x58]
	movs r2, #0
	strb r2, [r6]
	subs r3, #0x65
	adds r3, r7, r3
	str r3, [sp, #0x5c]
	strb r0, [r3]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x60]
	str r1, [r4]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x64]
	add r0, sp, #0x50
	ldrh r0, [r0]
	strh r0, [r6]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r2, [r4]
	ldr r2, _0812B3D4 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0812B3D8 @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x50]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xc4]
	str r2, [sp, #0xc8]
	str r1, [sp, #0xd8]
	str r0, [sp, #0xd0]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0xd4]
	ldr r1, [sp, #0x58]
	str r1, [sp, #0xcc]
	ldr r2, [sp, #0x5c]
	str r2, [sp, #0xec]
	ldr r3, [sp, #0x60]
	str r3, [sp, #0xf4]
	ldr r4, [sp, #0x64]
	str r4, [sp, #0x100]
	b _0812B5AA
	.align 2, 0
_0812B3CC: .4byte 0x0000046D
_0812B3D0: .4byte 0x0000046B
_0812B3D4: .4byte 0x00000469
_0812B3D8: .4byte 0x00000484
_0812B3DC:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r6, _0812B49C @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x68]
	strb r0, [r6]
	ldr r3, _0812B4A0 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x4d
	adds r5, r7, r5
	str r5, [sp, #0x70]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x74]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	strb r4, [r3]
	ldr r4, _0812B4A4 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r3, _0812B4A8 @ =0x0000046A
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0812B4AC @ =0x00000484
	adds r3, r7, r6
	str r2, [r3]
	ldr r1, _0812B4B0 @ =0x0000046C
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, [sp, #0xdc]
	ldr r6, [r6]
	str r6, [sp, #0x80]
	ldr r1, [sp, #0xf0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r6, [sp, #0xf0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x80]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x7c]
	str r0, [sp, #0xc0]
	str r5, [sp, #0xc4]
	str r4, [sp, #0xc8]
	str r3, [sp, #0xd8]
	str r2, [sp, #0xd0]
	ldr r2, [sp, #0x68]
	str r2, [sp, #0xd4]
	ldr r3, [sp, #0x6c]
	str r3, [sp, #0xcc]
	ldr r4, [sp, #0x70]
	str r4, [sp, #0xec]
	ldr r5, [sp, #0x74]
	str r5, [sp, #0xf4]
	ldr r6, [sp, #0x78]
	str r6, [sp, #0x100]
	mov r0, sb
	cmp r0, #0
	blt _0812B496
	cmp r1, #0
	blt _0812B496
	ldr r0, _0812B4B4 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _0812B496
	ldr r0, _0812B4B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812B4BC
_0812B496:
	movs r4, #0
	b _0812B4CC
	.align 2, 0
_0812B49C: .4byte 0x0000046D
_0812B4A0: .4byte 0x0000046B
_0812B4A4: .4byte 0x00000469
_0812B4A8: .4byte 0x0000046A
_0812B4AC: .4byte 0x00000484
_0812B4B0: .4byte 0x0000046C
_0812B4B4: .4byte 0x030046A8
_0812B4B8: .4byte 0x030046AC
_0812B4BC:
	ldr r0, _0812B4DC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_0812B4CC:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812B4E0
	adds r0, #4
	b _0812B4EC
	.align 2, 0
_0812B4DC: .4byte 0x030046A4
_0812B4E0:
	ldr r0, _0812B500 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812B4EC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812B504
	cmp r2, #2
	beq _0812B50A
	b _0812B510
	.align 2, 0
_0812B500: .4byte 0x030046A4
_0812B504:
	ldr r2, [sp, #0x80]
	ldrb r0, [r2, #4]
	b _0812B50E
_0812B50A:
	ldr r3, [sp, #0x80]
	ldrb r0, [r3]
_0812B50E:
	subs r1, r1, r0
_0812B510:
	ldr r4, [sp, #0x80]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xdc]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812B53C
	cmp r1, #0
	blt _0812B53C
	ldr r0, _0812B540 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812B53C
	ldr r0, _0812B544 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812B548
_0812B53C:
	movs r4, #0
	b _0812B556
	.align 2, 0
_0812B540: .4byte 0x030046A8
_0812B544: .4byte 0x030046AC
_0812B548:
	ldr r0, _0812B56C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812B556:
	ldr r6, [sp, #0xdc]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812B570
	adds r0, #4
	b _0812B57C
	.align 2, 0
_0812B56C: .4byte 0x030046A4
_0812B570:
	ldr r0, _0812B590 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812B57C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0812B594
	cmp r3, #2
	beq _0812B598
	b _0812B59C
	.align 2, 0
_0812B590: .4byte 0x030046A4
_0812B594:
	ldrb r0, [r5, #4]
	b _0812B59A
_0812B598:
	ldrb r0, [r5]
_0812B59A:
	subs r2, r2, r0
_0812B59C:
	ldr r1, [sp, #0xdc]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xdc]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0812B5AA:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x84]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xfc]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _0812B5D4 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _0812B6B4
	movs r1, #4
	ldr r2, [sp, #0x104]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0812B5D8
	movs r0, #1
	b _0812B5DA
	.align 2, 0
_0812B5D4: .4byte 0x00000482
_0812B5D8:
	movs r0, #0
_0812B5DA:
	ldr r3, _0812B6C4 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _0812B6B4
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0812B6C8 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0812B6CC @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0812B6D0 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	ldr r0, _0812B6D4 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xe0]
	ldr r1, _0812B6D8 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _0812B6DC @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r1, _0812B6E0 @ =0x030046B8
	str r4, [sp, #0x108]
_0812B620:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0812B6E4 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0812B6E8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x108]
	cmp r0, r2
	bne _0812B646
	adds r3, #1
	cmp r3, #3
	ble _0812B620
	adds r0, r4, #0
_0812B646:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xf4]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xec]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xc4]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc8]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe8]
	strb r0, [r6]
	add r0, sp, #0x84
	ldrb r1, [r0]
	ldr r0, [sp, #0xe0]
	strb r1, [r0]
	ldr r1, [sp, #0xf8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xd4]
	strb r1, [r4]
	ldr r6, [sp, #0xcc]
	strb r3, [r6]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r6, [sp, #0xf4]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x100]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xc0]
	strb r0, [r4]
	ldr r6, [sp, #0xc4]
	strb r1, [r6]
	ldr r0, [sp, #0xc8]
	strb r2, [r0]
	ldr r2, [sp, #0xd8]
	str r3, [r2]
	ldr r3, [sp, #0xd0]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
_0812B6B4:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _0812B7C2
	.align 2, 0
_0812B6C4: .4byte 0x00000482
_0812B6C8: .4byte 0x0000054F
_0812B6CC: .4byte 0x0000054D
_0812B6D0: .4byte 0x0000054E
_0812B6D4: .4byte 0x00000541
_0812B6D8: .4byte 0x000005BC
_0812B6DC: .4byte 0x00000542
_0812B6E0: .4byte 0x030046B8
_0812B6E4: .4byte 0x000003FF
_0812B6E8: .4byte 0x0203B400
_0812B6EC:
	add r6, sp, #8
	ldr r0, _0812B72C @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _0812B730
	adds r0, #4
	b _0812B73C
	.align 2, 0
_0812B72C: .4byte 0x030046A4
_0812B730:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812B73C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0812B770 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0812B774
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0812B79A
	.align 2, 0
_0812B770: .4byte 0x000004A4
_0812B774:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0812B794
	cmp r0, #2
	beq _0812B790
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812B790:
	movs r0, #1
	b _0812B7A4
_0812B794:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0812B79A:
	ldr r1, _0812B7B8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812B7A4:
	cmp r0, #0
	bne _0812B7C0
_0812B7A8:
	ldr r2, _0812B7BC @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0812B7C2
	.align 2, 0
_0812B7B8: .4byte 0xFFFFFDFF
_0812B7BC: .4byte 0x000005C4
_0812B7C0:
	movs r0, #1
_0812B7C2:
	cmp r0, #0
	bne _0812B82E
	ldr r3, _0812B7F4 @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0812B7F8
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0812B81E
	.align 2, 0
_0812B7F4: .4byte 0x000004A4
_0812B7F8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0812B818
	cmp r0, #2
	beq _0812B814
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812B814:
	movs r0, #1
	b _0812B828
_0812B818:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0812B81E:
	ldr r1, _0812B884 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812B828:
	cmp r0, #0
	bne _0812B82E
	b _0812BF98
_0812B82E:
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r4, _0812B888 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0812B88C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0812B890 @ =0x00000553
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0812B894 @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0812B898 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	b _0812C008
	.align 2, 0
_0812B884: .4byte 0xFFFFFDFF
_0812B888: .4byte 0x0000046D
_0812B88C: .4byte 0x0000046B
_0812B890: .4byte 0x00000553
_0812B894: .4byte 0x0000046A
_0812B898: .4byte 0x00000484
_0812B89C:
	ldr r6, _0812B938 @ =0x0000048D
	adds r2, r7, r6
	ldrb r0, [r2]
	cmp r0, #0
	bne _0812B8C8
	ldr r1, _0812B93C @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0812B8C8
	ldr r3, _0812B940 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_0812B8C8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r3, r7, r4
	ldr r0, [r3]
	cmp r0, #0
	bne _0812B8D8
	bl _0812B084
_0812B8D8:
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	ldr r0, _0812B944 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r3]
	adds r3, r7, r6
	ldr r6, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0xdc]
	str r2, [sp, #0xf0]
	cmp r5, #0
	blt _0812B932
	cmp r1, #0
	blt _0812B932
	ldr r0, _0812B948 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _0812B932
	ldr r0, _0812B94C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812B950
_0812B932:
	movs r4, #0
	b _0812B95E
	.align 2, 0
_0812B938: .4byte 0x0000048D
_0812B93C: .4byte 0x0000048C
_0812B940: .4byte 0x000004BE
_0812B944: .4byte 0x03002BE0
_0812B948: .4byte 0x030046A8
_0812B94C: .4byte 0x030046AC
_0812B950:
	ldr r0, _0812B970 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r5
_0812B95E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812B974
	adds r0, #4
	b _0812B980
	.align 2, 0
_0812B970: .4byte 0x030046A4
_0812B974:
	ldr r0, _0812B994 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812B980:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812B998
	cmp r2, #2
	beq _0812B99C
	b _0812B9A0
	.align 2, 0
_0812B994: .4byte 0x030046A4
_0812B998:
	ldrb r0, [r6, #4]
	b _0812B99E
_0812B99C:
	ldrb r0, [r6]
_0812B99E:
	subs r1, r1, r0
_0812B9A0:
	strh r1, [r6, #2]
	ldr r0, _0812B9B4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812B9B8
	movs r0, #1
	b _0812B9BA
	.align 2, 0
_0812B9B4: .4byte 0x030047A4
_0812B9B8:
	movs r0, #0
_0812B9BA:
	cmp r0, #0
	beq _0812B9F0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0812B9CC
	b _0812BF14
_0812B9CC:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0812B9D8
	adds r2, r0, #0
_0812B9D8:
	cmp r2, #0
	bge _0812B9DE
	b _0812BF14
_0812B9DE:
	ldr r1, _0812B9EC @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0812BA38
	.align 2, 0
_0812B9EC: .4byte 0x03002BE0
_0812B9F0:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812BA1C
	cmp r1, #0
	blt _0812BA1C
	ldr r0, _0812BA20 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812BA1C
	ldr r0, _0812BA24 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812BA28
_0812BA1C:
	movs r5, #0
	b _0812BA36
	.align 2, 0
_0812BA20: .4byte 0x030046A8
_0812BA24: .4byte 0x030046AC
_0812BA28:
	ldr r0, _0812BA78 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0812BA36:
	movs r2, #0
_0812BA38:
	ldr r4, _0812BA7C @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0812BA58
	ldr r1, _0812BA80 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0812BA58
	b _0812BE58
_0812BA58:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x88]
	str r2, [sp, #0xfc]
	cmp r1, #0
	beq _0812BA84
	movs r0, #0
	b _0812BF2E
	.align 2, 0
_0812BA78: .4byte 0x030046A4
_0812BA7C: .4byte 0x00000256
_0812BA80: .4byte 0x03002BE0
_0812BA84:
	ldr r6, _0812BB2C @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0xfc]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0x104]
	cmp r0, #0
	beq _0812BB44
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0812BB30 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	movs r5, #1
	ldr r6, [sp, #0x8c]
	strb r5, [r6]
	ldr r2, _0812BB34 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x90]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x94]
	strb r0, [r4]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x98]
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r0, r7, r0
	str r0, [sp, #0x9c]
	add r1, sp, #0x88
	ldrh r1, [r1]
	strh r1, [r0]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	strb r3, [r4]
	ldr r6, _0812BB38 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0812BB3C @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x88]
	str r6, [r1]
	ldr r6, _0812BB40 @ =0x0000046C
	adds r0, r7, r6
	strb r5, [r0]
	str r4, [sp, #0xc0]
	str r3, [sp, #0xc4]
	str r2, [sp, #0xc8]
	str r1, [sp, #0xd8]
	str r0, [sp, #0xd0]
	ldr r0, [sp, #0x8c]
	str r0, [sp, #0xd4]
	ldr r1, [sp, #0x90]
	str r1, [sp, #0xcc]
	ldr r2, [sp, #0x94]
	str r2, [sp, #0xec]
	ldr r3, [sp, #0x98]
	str r3, [sp, #0xf4]
	ldr r4, [sp, #0x9c]
	str r4, [sp, #0x100]
	b _0812BD16
	.align 2, 0
_0812BB2C: .4byte 0x00000222
_0812BB30: .4byte 0x0000046D
_0812BB34: .4byte 0x0000046B
_0812BB38: .4byte 0x00000469
_0812BB3C: .4byte 0x00000484
_0812BB40: .4byte 0x0000046C
_0812BB44:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #1
	ldr r6, _0812BC08 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0xa0]
	strb r0, [r6]
	ldr r2, _0812BC0C @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	movs r3, #0
	strb r3, [r2]
	ldr r4, _0812BC10 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0xa8]
	strb r0, [r4]
	subs r5, #0x28
	adds r5, r7, r5
	str r5, [sp, #0xac]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0xb0]
	mov r1, ip
	strh r1, [r6]
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	strb r3, [r2]
	ldr r3, _0812BC14 @ =0x00000469
	adds r5, r7, r3
	movs r4, #0
	strb r4, [r5]
	ldr r6, _0812BC18 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _0812BC1C @ =0x00000484
	adds r3, r7, r1
	mov r2, ip
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0xdc]
	ldr r0, [r0]
	str r0, [sp, #0xb8]
	ldr r1, [sp, #0xf0]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0xb8]
	strh r1, [r6]
	ldr r6, [sp, #0xf0]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xb8]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0xb4]
	str r0, [sp, #0xc0]
	str r5, [sp, #0xc4]
	str r4, [sp, #0xc8]
	str r3, [sp, #0xd8]
	str r2, [sp, #0xd0]
	ldr r2, [sp, #0xa0]
	str r2, [sp, #0xd4]
	ldr r3, [sp, #0xa4]
	str r3, [sp, #0xcc]
	ldr r4, [sp, #0xa8]
	str r4, [sp, #0xec]
	ldr r5, [sp, #0xac]
	str r5, [sp, #0xf4]
	ldr r6, [sp, #0xb0]
	str r6, [sp, #0x100]
	mov r0, r8
	cmp r0, #0
	blt _0812BC02
	cmp r1, #0
	blt _0812BC02
	ldr r0, _0812BC20 @ =0x030046A8
	ldr r0, [r0]
	cmp r8, r0
	bhs _0812BC02
	ldr r0, _0812BC24 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812BC28
_0812BC02:
	movs r4, #0
	b _0812BC38
	.align 2, 0
_0812BC08: .4byte 0x0000046D
_0812BC0C: .4byte 0x0000046B
_0812BC10: .4byte 0x00000553
_0812BC14: .4byte 0x00000469
_0812BC18: .4byte 0x0000046A
_0812BC1C: .4byte 0x00000484
_0812BC20: .4byte 0x030046A8
_0812BC24: .4byte 0x030046AC
_0812BC28:
	ldr r0, _0812BC48 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, r8
	adds r4, r0, r1
_0812BC38:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812BC4C
	adds r0, #4
	b _0812BC58
	.align 2, 0
_0812BC48: .4byte 0x030046A4
_0812BC4C:
	ldr r0, _0812BC6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812BC58:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0812BC70
	cmp r2, #2
	beq _0812BC76
	b _0812BC7C
	.align 2, 0
_0812BC6C: .4byte 0x030046A4
_0812BC70:
	ldr r2, [sp, #0xb8]
	ldrb r0, [r2, #4]
	b _0812BC7A
_0812BC76:
	ldr r3, [sp, #0xb8]
	ldrb r0, [r3]
_0812BC7A:
	subs r1, r1, r0
_0812BC7C:
	ldr r4, [sp, #0xb8]
	strh r1, [r4, #2]
	ldr r5, [sp, #0xdc]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0812BCA8
	cmp r1, #0
	blt _0812BCA8
	ldr r0, _0812BCAC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0812BCA8
	ldr r0, _0812BCB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0812BCB4
_0812BCA8:
	movs r4, #0
	b _0812BCC2
	.align 2, 0
_0812BCAC: .4byte 0x030046A8
_0812BCB0: .4byte 0x030046AC
_0812BCB4:
	ldr r0, _0812BCD8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0812BCC2:
	ldr r6, [sp, #0xdc]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0812BCDC
	adds r0, #4
	b _0812BCE8
	.align 2, 0
_0812BCD8: .4byte 0x030046A4
_0812BCDC:
	ldr r0, _0812BCFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0812BCE8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0812BD00
	cmp r3, #2
	beq _0812BD04
	b _0812BD08
	.align 2, 0
_0812BCFC: .4byte 0x030046A4
_0812BD00:
	ldrb r0, [r5, #4]
	b _0812BD06
_0812BD04:
	ldrb r0, [r5]
_0812BD06:
	subs r2, r2, r0
_0812BD08:
	ldr r1, [sp, #0xdc]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0xdc]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0812BD16:
	ldrb r3, [r7, #5]
	str r3, [sp, #0xbc]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0xfc]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r6, _0812BD40 @ =0x00000482
	adds r5, r7, r6
	cmp r0, #0
	bne _0812BE20
	movs r1, #4
	ldr r2, [sp, #0x104]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0812BD44
	movs r0, #1
	b _0812BD46
	.align 2, 0
_0812BD40: .4byte 0x00000482
_0812BD44:
	movs r0, #0
_0812BD46:
	ldr r3, _0812BE30 @ =0x00000482
	adds r5, r7, r3
	cmp r0, #0
	bne _0812BE20
	movs r3, #0
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r6, r7, r0
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0812BE34 @ =0x0000054F
	adds r2, r2, r7
	mov sb, r2
	adds r0, #0xc
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0812BE38 @ =0x0000054D
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0812BE3C @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	ldr r0, _0812BE40 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xe0]
	ldr r1, _0812BE44 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xf8]
	ldr r2, _0812BE48 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xe4]
	ldr r1, _0812BE4C @ =0x030046B8
	str r4, [sp, #0x108]
_0812BD8C:
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0812BE50 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r2, _0812BE54 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	lsls r0, r0, #6
	ldr r2, [sp, #0x108]
	cmp r0, r2
	bne _0812BDB2
	adds r3, #1
	cmp r3, #3
	ble _0812BD8C
	adds r0, r4, #0
_0812BDB2:
	movs r3, #0
	strb r0, [r6]
	ldr r4, [sp, #0xf4]
	ldr r0, [r4]
	mov r6, r8
	str r0, [r6]
	ldr r1, [sp, #0xec]
	ldrb r0, [r1]
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0xc0]
	ldrb r0, [r4]
	mov r6, sl
	strb r0, [r6]
	ldr r1, [sp, #0xc4]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0xc8]
	ldrb r0, [r4]
	ldr r6, [sp, #0xe8]
	strb r0, [r6]
	add r0, sp, #0xbc
	ldrb r1, [r0]
	ldr r0, [sp, #0xe0]
	strb r1, [r0]
	ldr r1, [sp, #0xf8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0xd4]
	strb r1, [r4]
	ldr r6, [sp, #0xcc]
	strb r3, [r6]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r6, [sp, #0xf4]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x100]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0xc0]
	strb r0, [r4]
	ldr r6, [sp, #0xc4]
	strb r1, [r6]
	ldr r0, [sp, #0xc8]
	strb r2, [r0]
	ldr r2, [sp, #0xd8]
	str r3, [r2]
	ldr r3, [sp, #0xd0]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xe4]
	strb r0, [r4]
_0812BE20:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	strh r0, [r5]
	movs r0, #0
	b _0812BF2E
	.align 2, 0
_0812BE30: .4byte 0x00000482
_0812BE34: .4byte 0x0000054F
_0812BE38: .4byte 0x0000054D
_0812BE3C: .4byte 0x0000054E
_0812BE40: .4byte 0x00000541
_0812BE44: .4byte 0x000005BC
_0812BE48: .4byte 0x00000542
_0812BE4C: .4byte 0x030046B8
_0812BE50: .4byte 0x000003FF
_0812BE54: .4byte 0x0203B400
_0812BE58:
	add r6, sp, #0x10
	ldr r0, _0812BE98 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	mov sl, r6
	cmp r0, #0
	beq _0812BE9C
	adds r0, #4
	b _0812BEA8
	.align 2, 0
_0812BE98: .4byte 0x030046A4
_0812BE9C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0812BEA8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0812BEDC @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0812BEE0
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0812BF06
	.align 2, 0
_0812BEDC: .4byte 0x000004A4
_0812BEE0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0812BF00
	cmp r0, #2
	beq _0812BEFC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812BEFC:
	movs r0, #1
	b _0812BF10
_0812BF00:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0812BF06:
	ldr r1, _0812BF24 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812BF10:
	cmp r0, #0
	bne _0812BF2C
_0812BF14:
	ldr r2, _0812BF28 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0812BF2E
	.align 2, 0
_0812BF24: .4byte 0xFFFFFDFF
_0812BF28: .4byte 0x000005C4
_0812BF2C:
	movs r0, #1
_0812BF2E:
	cmp r0, #0
	bne _0812BFB0
	ldr r3, _0812BF60 @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0812BF64
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0812BF8A
	.align 2, 0
_0812BF60: .4byte 0x000004A4
_0812BF64:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0812BF84
	cmp r0, #2
	beq _0812BF80
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0812BF80:
	movs r0, #1
	b _0812BF94
_0812BF84:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0812BF8A:
	ldr r1, _0812BFA8 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0812BF94:
	cmp r0, #0
	bne _0812BFB0
_0812BF98:
	ldr r1, _0812BFAC @ =0x000005C4
	adds r0, r7, r1
FUN_0812bf9c:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _0812B084
	.align 2, 0
_0812BFA8: .4byte 0xFFFFFDFF
_0812BFAC: .4byte 0x000005C4
_0812BFB0:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r3, #1
	ldr r4, _0812C01C @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r3, [r0]
	ldr r5, _0812C020 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0812C024 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r1, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r5, _0812C028 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _0812C02C @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _0812C030 @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _0812C034 @ =0x00000482
	adds r1, r7, r3
FUN_0812c004:
	movs r0, #3
	strh r0, [r1]
_0812C008:
	movs r0, #1
FUN_0812c00a:
	add sp, #0x10c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0812C01C: .4byte 0x0000046D
_0812C020: .4byte 0x0000046B
_0812C024: .4byte 0x00000553
_0812C028: .4byte 0x00000469
_0812C02C: .4byte 0x00000484
_0812C030: .4byte 0x0000046C
_0812C034: .4byte 0x00000482
