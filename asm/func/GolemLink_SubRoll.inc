	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x6c
	str r0, [sp, #0x18]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	ldr r2, [sp, #0x18]
	ldr r3, _081BEC84 @ =0x0000046C
	adds r1, r2, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BEC88
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081BEC8A
	.align 2, 0
_081BEC84: .4byte 0x0000046C
_081BEC88:
	movs r0, #0
_081BEC8A:
	cmp r0, #0
	beq _081BEC96
	ldr r4, _081BECE0 @ =0x00000659
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
_081BEC96:
	ldr r0, [sp, #0x18]
	bl GolemLink_TryChaseHitTarget
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081BECA6
	bl _081BFCB2
_081BECA6:
	ldr r6, _081BECE0 @ =0x00000659
	adds r5, r7, r6
	ldrb r0, [r5]
	cmp r0, #1
	bne _081BECC6
	ldr r1, _081BECE4 @ =0x000006B6
	adds r0, r7, r1
	movs r2, #0
	ldrsh r4, [r0, r2]
	cmp r4, #0
	bne _081BECC6
	ldr r0, [sp, #0x18]
	movs r1, #4
	bl PlayGolemSound
	strb r4, [r5]
_081BECC6:
	ldr r0, [sp, #0x18]
	bl GolemLink_Accelerate
	ldr r0, _081BECE8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BECEC
	movs r0, #1
	b _081BECEE
	.align 2, 0
_081BECE0: .4byte 0x00000659
_081BECE4: .4byte 0x000006B6
_081BECE8: .4byte 0x030047A4
_081BECEC:
	movs r0, #0
_081BECEE:
	cmp r0, #0
	beq _081BED58
	ldr r3, [sp, #0x18]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081BEDA8
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BED0C
	adds r2, r0, #0
_081BED0C:
	cmp r2, #0
	blt _081BEDA8
	ldr r1, _081BED38 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081BEDA8
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r5, _081BED3C @ =0x0000065C
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081BED40
	movs r0, #1
	b _081BED42
	.align 2, 0
_081BED38: .4byte 0x03002BE0
_081BED3C: .4byte 0x0000065C
_081BED40:
	movs r0, #0
_081BED42:
	adds r5, r0, #0
	cmp r5, #0
	bne _081BEDA8
	ldr r6, _081BED54 @ =0x000006B4
	adds r1, r7, r6
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	b _081BF136
	.align 2, 0
_081BED54: .4byte 0x000006B4
_081BED58:
	ldr r0, _081BED7C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081BEDA8
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r2, _081BED80 @ =0x0000065C
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081BED84
	movs r0, #1
	b _081BED86
	.align 2, 0
_081BED7C: .4byte 0x03002BE0
_081BED80: .4byte 0x0000065C
_081BED84:
	movs r0, #0
_081BED86:
	adds r5, r0, #0
	cmp r5, #0
	bne _081BEDA8
	ldr r3, _081BEDA0 @ =0x000006B4
	adds r1, r7, r3
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	strh r0, [r1]
	ldr r6, _081BEDA4 @ =0x000006C4
	adds r0, r7, r6
	b _081BF13C
	.align 2, 0
_081BEDA0: .4byte 0x000006B4
_081BEDA4: .4byte 0x000006C4
_081BEDA8:
	ldr r2, [sp, #0x18]
	ldr r3, _081BEE54 @ =0x000004A4
	adds r0, r2, r3
	ldr r2, [r0]
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _081BEDC0
	b _081BF2DC
_081BEDC0:
	ldr r4, _081BEE58 @ =0x000006B6
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x18]
	adds r1, r2, #0
	movs r2, #0x18
	movs r3, #0x18
	bl GolemLink_MoveAlongNavAxis
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081BEDE2
	b _081BF1C0
_081BEDE2:
	movs r6, #0xda
	lsls r6, r6, #3
	adds r2, r7, r6
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	add r3, sp, #8
	ldr r4, [sp, #0x18]
	adds r4, #8
	ldrh r0, [r2]
	ldr r5, [sp, #0x18]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r3, #0
	movs r6, #0
	ldrsh r0, [r0, r6]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r3, r1, r0
	ldr r5, _081BEE5C @ =0x000006C2
	adds r2, r7, r5
	ldr r6, _081BEE60 @ =0x00000659
	adds r1, r7, r6
	movs r0, #1
	strb r0, [r1]
	ldr r1, [sp, #0x18]
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r1, r5
	ldrb r1, [r0]
	ldrb r0, [r2]
	subs r1, r1, r0
	adds r6, r4, #0
	cmp r1, #0x80
	ble _081BEE68
	ldr r0, _081BEE64 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081BEE76
	.align 2, 0
_081BEE54: .4byte 0x000004A4
_081BEE58: .4byte 0x000006B6
_081BEE5C: .4byte 0x000006C2
_081BEE60: .4byte 0x00000659
_081BEE64: .4byte 0xFFFFFF00
_081BEE68:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BEE76
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081BEE76:
	cmp r1, #0
	bge _081BEE7C
	rsbs r1, r1, #0
_081BEE7C:
	cmp r1, #0xf
	bgt _081BEEB8
	ldr r0, _081BEEA8 @ =0x0000FFFE
	cmp r3, r0
	bgt _081BEEB8
	ldr r3, _081BEEAC @ =0x000006B6
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0xc7
	ble _081BEEB8
	ldr r5, _081BEEB0 @ =0x000006B4
	adds r1, r7, r5
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	movs r5, #0
	strh r0, [r1]
	ldr r6, _081BEEB4 @ =0x000006C4
	adds r0, r7, r6
	b _081BF13C
	.align 2, 0
_081BEEA8: .4byte 0x0000FFFE
_081BEEAC: .4byte 0x000006B6
_081BEEB0: .4byte 0x000006B4
_081BEEB4: .4byte 0x000006C4
_081BEEB8:
	ldr r2, _081BEEDC @ =0x000006C2
	adds r0, r7, r2
	ldrb r4, [r0]
	add r1, sp, #8
	adds r0, r1, #0
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #4
	ldrsh r1, [r1, r5]
	bl ArcTan2_8
	subs r1, r0, r4
	cmp r1, #0x80
	ble _081BEEE4
	ldr r0, _081BEEE0 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081BEEF2
	.align 2, 0
_081BEEDC: .4byte 0x000006C2
_081BEEE0: .4byte 0xFFFFFF00
_081BEEE4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BEEF2
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081BEEF2:
	adds r0, r1, #0
	cmp r0, #0
	bge _081BEEFA
	rsbs r0, r0, #0
_081BEEFA:
	cmp r0, #0xf
	bgt _081BEFA0
	movs r3, #0xda
	lsls r3, r3, #3
	adds r0, r7, r3
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BEF28
	cmp r1, #0
	blt _081BEF28
	ldr r0, _081BEF2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BEF28
	ldr r0, _081BEF30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BEF34
_081BEF28:
	movs r5, #0
	b _081BEF42
	.align 2, 0
_081BEF2C: .4byte 0x030046A8
_081BEF30: .4byte 0x030046AC
_081BEF34:
	ldr r0, _081BEF54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BEF42:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BEF58
	adds r0, #4
	b _081BEF64
	.align 2, 0
_081BEF54: .4byte 0x030046A4
_081BEF58:
	ldr r0, _081BEF98 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BEF64:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	ldr r4, _081BEF9C @ =0x000006C2
	adds r0, r7, r4
	ldrb r0, [r0]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r4, r0, #6
	adds r0, r5, #0
	adds r2, r4, #0
	bl GolemLink_ClassifyNextTile
	cmp r0, #0
	bne _081BEF90
	movs r5, #0xda
	lsls r5, r5, #3
	adds r0, r7, r5
	adds r1, r4, #0
	bl GolemLink_SnapToNextTile
_081BEF90:
	adds r0, r7, #0
	bl GolemLink_RouteTo
	b _081BEFAC
	.align 2, 0
_081BEF98: .4byte 0x030046A4
_081BEF9C: .4byte 0x000006C2
_081BEFA0:
	subs r0, #0x34
	cmp r0, #0x18
	bhi _081BEFAC
	adds r0, r7, #0
	bl GolemLink_RouteTo
_081BEFAC:
	ldr r1, _081BEFC4 @ =0x000006C4
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _081BEFC8 @ =0x000006C2
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081BEFD0
	ldr r3, _081BEFCC @ =0xFFFFFF00
	adds r1, r1, r3
	b _081BEFDE
	.align 2, 0
_081BEFC4: .4byte 0x000006C4
_081BEFC8: .4byte 0x000006C2
_081BEFCC: .4byte 0xFFFFFF00
_081BEFD0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BEFDE
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_081BEFDE:
	cmp r1, #0
	bge _081BEFE4
	rsbs r1, r1, #0
_081BEFE4:
	cmp r1, #0x1f
	ble _081BF058
	ldr r5, _081BF03C @ =0x000006C4
	adds r2, r7, r5
	ldrb r1, [r2]
	ldr r6, _081BF040 @ =0x000006C5
	adds r0, r7, r6
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r0, _081BF044 @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _081BF00E
	b _081BF430
_081BF00E:
	ldr r2, _081BF048 @ =GolemLink_StateUncurl
	movs r1, #0x26
	ldr r3, _081BF04C @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _081BF050 @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _081BF054 @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #3
	b _081BF46E
	.align 2, 0
_081BF03C: .4byte 0x000006C4
_081BF040: .4byte 0x000006C5
_081BF044: .4byte 0x000006B4
_081BF048: .4byte GolemLink_StateUncurl
_081BF04C: .4byte 0x0000046D
_081BF050: .4byte 0x0000046B
_081BF054: .4byte 0x00000553
_081BF058:
	add r2, sp, #8
	ldr r1, [sp, #0x18]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r1, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r1, #8]
	subs r0, r0, r1
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	adds r0, r2, #0
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r5, #4
	ldrsh r0, [r2, r5]
	adds r6, r0, #0
	muls r6, r0, r6
	adds r0, r6, #0
	adds r3, r1, r0
	ldr r0, _081BF0BC @ =0x0000FFFE
	cmp r3, r0
	bgt _081BF12A
	ldr r1, _081BF0C0 @ =0x000006B6
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xc7
	ble _081BF12A
	ldr r0, _081BF0C4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BF0C8
	movs r0, #1
	b _081BF0CA
	.align 2, 0
_081BF0BC: .4byte 0x0000FFFE
_081BF0C0: .4byte 0x000006B6
_081BF0C4: .4byte 0x030047A4
_081BF0C8:
	movs r0, #0
_081BF0CA:
	cmp r0, #0
	beq _081BF110
	ldr r3, [sp, #0x18]
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r3, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081BF12A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BF0E8
	adds r2, r0, #0
_081BF0E8:
	cmp r2, #0
	blt _081BF12A
	ldr r1, _081BF108 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BF12A
	ldr r5, _081BF10C @ =0x000006BC
	adds r1, r7, r5
	b _081BF124
	.align 2, 0
_081BF108: .4byte 0x03002BE0
_081BF10C: .4byte 0x000006BC
_081BF110:
	ldr r0, _081BF194 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BF12A
	ldr r6, _081BF198 @ =0x000006BC
	adds r1, r7, r6
_081BF124:
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r1]
_081BF12A:
	ldr r0, _081BF19C @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0x1e
	movs r4, #0
	movs r5, #0
_081BF136:
	strh r0, [r1]
	ldr r1, _081BF1A0 @ =0x000006C4
	adds r0, r7, r1
_081BF13C:
	ldrb r1, [r0]
	ldr r2, _081BF1A4 @ =0x000006C5
	adds r0, r7, r2
	strb r1, [r0]
	movs r1, #2
	movs r2, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r6, _081BF1A8 @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081BF1AC @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _081BF1B0 @ =0x00000484
	adds r0, r7, r2
	str r5, [r0]
	adds r3, #4
	adds r0, r7, r3
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081BF1B4 @ =GolemLink_StateBrake
	movs r2, #0x2a
	adds r6, #4
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _081BF1B8 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _081BF1BC @ =0x00000553
	adds r0, r7, r4
	strb r2, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	bl _081BFCB2
	.align 2, 0
_081BF194: .4byte 0x03002BE0
_081BF198: .4byte 0x000006BC
_081BF19C: .4byte 0x000006B4
_081BF1A0: .4byte 0x000006C4
_081BF1A4: .4byte 0x000006C5
_081BF1A8: .4byte 0x00000469
_081BF1AC: .4byte 0x0000046A
_081BF1B0: .4byte 0x00000484
_081BF1B4: .4byte GolemLink_StateBrake
_081BF1B8: .4byte 0x0000046B
_081BF1BC: .4byte 0x00000553
_081BF1C0:
	ldr r2, [sp, #0x18]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrb r1, [r0]
	ldr r4, _081BF1DC @ =0x000006C2
	adds r0, r7, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081BF1E4
	ldr r5, _081BF1E0 @ =0xFFFFFF00
	adds r1, r1, r5
	b _081BF1F2
	.align 2, 0
_081BF1DC: .4byte 0x000006C2
_081BF1E0: .4byte 0xFFFFFF00
_081BF1E4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BF1F2
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r1, r6
_081BF1F2:
	cmp r1, #0
	bge _081BF1F8
	rsbs r1, r1, #0
_081BF1F8:
	cmp r1, #0xf
	bgt _081BF22A
	ldr r1, [sp, #0x18]
	ldr r2, _081BF244 @ =0x00000256
	adds r0, r1, r2
	movs r3, #0x96
	lsls r3, r3, #2
	adds r1, r1, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081BF22A
	movs r4, #0xda
	lsls r4, r4, #3
	adds r2, r7, r4
	movs r5, #0xd9
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl GolemLink_RouteTo
_081BF22A:
	ldr r6, _081BF248 @ =0x000006C4
	adds r0, r7, r6
	ldrb r1, [r0]
	ldr r2, _081BF24C @ =0x000006C2
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081BF254
	ldr r3, _081BF250 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081BF262
	.align 2, 0
_081BF244: .4byte 0x00000256
_081BF248: .4byte 0x000006C4
_081BF24C: .4byte 0x000006C2
_081BF250: .4byte 0xFFFFFF00
_081BF254:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BF262
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r1, r4
_081BF262:
	cmp r1, #0
	bge _081BF268
	rsbs r1, r1, #0
_081BF268:
	cmp r1, #0x1f
	bgt _081BF26E
	b _081BF4A0
_081BF26E:
	ldr r5, _081BF2C0 @ =0x000006C4
	adds r2, r7, r5
	ldrb r1, [r2]
	ldr r6, _081BF2C4 @ =0x000006C5
	adds r0, r7, r6
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r0, _081BF2C8 @ =0x000006B4
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _081BF294
	b _081BF430
_081BF294:
	ldr r2, _081BF2CC @ =GolemLink_StateUncurl
	movs r1, #0x26
	ldr r3, _081BF2D0 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _081BF2D4 @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _081BF2D8 @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #3
	b _081BF46E
	.align 2, 0
_081BF2C0: .4byte 0x000006C4
_081BF2C4: .4byte 0x000006C5
_081BF2C8: .4byte 0x000006B4
_081BF2CC: .4byte GolemLink_StateUncurl
_081BF2D0: .4byte 0x0000046D
_081BF2D4: .4byte 0x0000046B
_081BF2D8: .4byte 0x00000553
_081BF2DC:
	ldr r3, _081BF318 @ =0x000006B6
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [sp, #0x18]
	adds r1, r2, #0
	movs r2, #0x18
	movs r3, #0x18
	bl GolemLink_MoveAlongNavAxis
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081BF31C
	movs r5, #0xda
	lsls r5, r5, #3
	adds r2, r7, r5
	movs r6, #0xd9
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl GolemLink_RouteTo
	b _081BF386
	.align 2, 0
_081BF318: .4byte 0x000006B6
_081BF31C:
	ldr r1, [sp, #0x18]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r1, [r0]
	ldr r3, _081BF338 @ =0x000006C2
	adds r0, r7, r3
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081BF340
	ldr r4, _081BF33C @ =0xFFFFFF00
	adds r1, r1, r4
	b _081BF34E
	.align 2, 0
_081BF338: .4byte 0x000006C2
_081BF33C: .4byte 0xFFFFFF00
_081BF340:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BF34E
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_081BF34E:
	cmp r1, #0
	bge _081BF354
	rsbs r1, r1, #0
_081BF354:
	cmp r1, #0xf
	bgt _081BF386
	ldr r6, [sp, #0x18]
	ldr r1, _081BF3A0 @ =0x00000256
	adds r0, r6, r1
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _081BF386
	movs r3, #0xda
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r4, #0xd9
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl GolemLink_RouteTo
_081BF386:
	ldr r5, _081BF3A4 @ =0x000006C4
	adds r0, r7, r5
	ldrb r1, [r0]
	ldr r6, _081BF3A8 @ =0x000006C2
	adds r0, r7, r6
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081BF3B0
	ldr r0, _081BF3AC @ =0xFFFFFF00
	adds r1, r1, r0
	b _081BF3BE
	.align 2, 0
_081BF3A0: .4byte 0x00000256
_081BF3A4: .4byte 0x000006C4
_081BF3A8: .4byte 0x000006C2
_081BF3AC: .4byte 0xFFFFFF00
_081BF3B0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081BF3BE
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081BF3BE:
	cmp r1, #0
	bge _081BF3C4
	rsbs r1, r1, #0
_081BF3C4:
	cmp r1, #0x1f
	ble _081BF4A0
	ldr r3, _081BF418 @ =0x000006C4
	adds r2, r7, r3
	ldrb r1, [r2]
	ldr r4, _081BF41C @ =0x000006C5
	adds r0, r7, r4
	movs r4, #0
	strb r1, [r0]
	ldrb r0, [r2]
	strb r0, [r7, #5]
	ldr r5, _081BF420 @ =0x000006B4
	adds r1, r7, r5
	ldrh r0, [r1]
	subs r0, #0xa
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _081BF430
	ldr r2, _081BF424 @ =GolemLink_StateUncurl
	movs r1, #0x26
	ldr r6, _081BF428 @ =0x0000046D
	adds r0, r7, r6
	movs r3, #1
	strb r3, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _081BF42C @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #3
	b _081BF46E
	.align 2, 0
_081BF418: .4byte 0x000006C4
_081BF41C: .4byte 0x000006C5
_081BF420: .4byte 0x000006B4
_081BF424: .4byte GolemLink_StateUncurl
_081BF428: .4byte 0x0000046D
_081BF42C: .4byte 0x00000553
_081BF430:
	movs r0, #0xda
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r1, _081BF484 @ =0x000004A4
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _081BF488 @ =GolemLink_StateStopAndTurn
	movs r1, #0x25
	ldr r3, _081BF48C @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _081BF490 @ =0x0000046B
	adds r0, r7, r6
	strb r5, [r0]
	ldr r5, _081BF494 @ =0x00000553
	adds r0, r7, r5
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #2
_081BF46E:
	ldr r2, _081BF498 @ =0x0000046A
	adds r0, r7, r2
	strb r1, [r0]
	subs r5, #0xcf
	adds r0, r7, r5
	str r4, [r0]
	ldr r6, _081BF49C @ =0x0000046C
	adds r0, r7, r6
	strb r3, [r0]
	bl _081BFCB2
	.align 2, 0
_081BF484: .4byte 0x000004A4
_081BF488: .4byte GolemLink_StateStopAndTurn
_081BF48C: .4byte 0x0000046D
_081BF490: .4byte 0x0000046B
_081BF494: .4byte 0x00000553
_081BF498: .4byte 0x0000046A
_081BF49C: .4byte 0x0000046C
_081BF4A0:
	ldr r1, _081BF5D0 @ =0x000006B4
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _081BF4B0
	bl _081BFC9C
_081BF4B0:
	ldr r0, [sp, #0x18]
	movs r1, #0
	bl Enemy_PlayAnim
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	ldr r3, [sp, #0x18]
	adds r4, r3, r4
	str r4, [sp, #0x1c]
	movs r1, #0
	strb r0, [r4]
	ldr r5, _081BF5D4 @ =0x00000469
	adds r5, r3, r5
	str r5, [sp, #0x20]
	movs r6, #1
	strb r6, [r5]
	ldr r0, _081BF5D8 @ =0x0000046A
	adds r3, r3, r0
	mov ip, r3
	strb r1, [r3]
	ldr r2, [sp, #0x18]
	ldr r3, _081BF5DC @ =0x00000484
	adds r2, r2, r3
	mov sl, r2
	str r1, [r2]
	ldr r4, [sp, #0x18]
	ldr r5, _081BF5E0 @ =0x0000046C
	adds r6, r4, r5
	movs r0, #1
	strb r0, [r6]
	ldr r2, _081BF5E4 @ =Enemy_WaitPendingState
	movs r0, #0xe
	subs r3, #0x17
	adds r4, r4, r3
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r3, [sp, #0x18]
	ldr r4, _081BF5E8 @ =0x0000046B
	adds r3, r3, r4
	mov r8, r3
	strb r1, [r3]
	ldr r3, [sp, #0x18]
	adds r4, #0xe8
	adds r5, r3, r4
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r3, r0
	str r2, [r4]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r3, r3, r2
	strh r1, [r3]
	ldr r0, [sp, #0x18]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r0, _081BF5EC @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ands r1, r0
	str r6, [sp, #0x40]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0x30]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x34]
	mov r6, ip
	str r6, [sp, #0x38]
	mov r0, sl
	str r0, [sp, #0x4c]
	mov r6, sb
	str r6, [sp, #0x44]
	mov r0, r8
	str r0, [sp, #0x3c]
	str r5, [sp, #0x68]
	str r4, [sp, #0x28]
	str r3, [sp, #0x58]
	mov sl, r2
	cmp r1, #0
	bne _081BF55A
	b _081BFB30
_081BF55A:
	ldr r1, [sp, #0x18]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	ldr r5, [sp, #0x18]
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081BF5F0 @ =0x00000551
	adds r0, r5, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r5, r0
	ldr r5, [r3]
	ldr r2, [sp, #0x18]
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _081BF5CA
	cmp r1, #0
	blt _081BF5CA
	ldr r0, _081BF5F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081BF5CA
	ldr r0, _081BF5F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BF5FC
_081BF5CA:
	movs r4, #0
	b _081BF60A
	.align 2, 0
_081BF5D0: .4byte 0x000006B4
_081BF5D4: .4byte 0x00000469
_081BF5D8: .4byte 0x0000046A
_081BF5DC: .4byte 0x00000484
_081BF5E0: .4byte 0x0000046C
_081BF5E4: .4byte Enemy_WaitPendingState
_081BF5E8: .4byte 0x0000046B
_081BF5EC: .4byte 0xFFFFFEFF
_081BF5F0: .4byte 0x00000551
_081BF5F4: .4byte 0x030046A8
_081BF5F8: .4byte 0x030046AC
_081BF5FC:
	ldr r0, _081BF61C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081BF60A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BF620
	adds r0, #4
	b _081BF62C
	.align 2, 0
_081BF61C: .4byte 0x030046A4
_081BF620:
	ldr r0, _081BF640 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BF62C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BF644
	cmp r2, #2
	beq _081BF648
	b _081BF64C
	.align 2, 0
_081BF640: .4byte 0x030046A4
_081BF644:
	ldrb r0, [r5, #4]
	b _081BF64A
_081BF648:
	ldrb r0, [r5]
_081BF64A:
	subs r1, r1, r0
_081BF64C:
	strh r1, [r5, #2]
	ldr r0, _081BF660 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081BF664
	movs r0, #1
	b _081BF666
	.align 2, 0
_081BF660: .4byte 0x030047A4
_081BF664:
	movs r0, #0
_081BF666:
	cmp r0, #0
	beq _081BF6AC
	ldr r1, [sp, #0x18]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _081BF688
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081BF684
	adds r2, r0, #0
_081BF684:
	cmp r2, #0
	bge _081BF698
_081BF688:
	ldr r3, [sp, #0x18]
	ldr r4, _081BF694 @ =0x000005C4
	adds r0, r3, r4
	ldr r1, [r0]
	adds r0, r3, #0
	b _081BFB06
	.align 2, 0
_081BF694: .4byte 0x000005C4
_081BF698:
	ldr r1, _081BF6A8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081BF6F8
	.align 2, 0
_081BF6A8: .4byte 0x03002BE0
_081BF6AC:
	ldr r5, [sp, #0x18]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BF6DA
	cmp r1, #0
	blt _081BF6DA
	ldr r0, _081BF6E0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BF6DA
	ldr r0, _081BF6E4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BF6E8
_081BF6DA:
	movs r5, #0
	b _081BF6F6
	.align 2, 0
_081BF6E0: .4byte 0x030046A8
_081BF6E4: .4byte 0x030046AC
_081BF6E8:
	ldr r0, _081BF730 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081BF6F6:
	movs r2, #0
_081BF6F8:
	ldr r3, [sp, #0x18]
	ldr r4, _081BF734 @ =0x00000256
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081BF71A
	ldr r1, _081BF738 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081BF71A
	b _081BFA3C
_081BF71A:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081BF73C
	movs r0, #0
	b _081BFB1A
	.align 2, 0
_081BF730: .4byte 0x030046A4
_081BF734: .4byte 0x00000256
_081BF738: .4byte 0x03002BE0
_081BF73C:
	ldr r0, [sp, #0x18]
	ldr r1, _081BF79C @ =0x00000222
	adds r2, r0, r1
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081BF7A0
	ldr r6, [sp, #0x18]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x44]
	strb r2, [r3]
	ldr r6, [sp, #0x3c]
	strb r5, [r6]
	ldr r3, [sp, #0x68]
	strb r0, [r3]
	ldr r6, [sp, #0x28]
	str r1, [r6]
	ldr r0, [sp, #0x58]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x30]
	strb r5, [r1]
	ldr r3, [sp, #0x34]
	strb r5, [r3]
	ldr r5, [sp, #0x38]
	strb r0, [r5]
	ldr r6, [sp, #0x4c]
	str r4, [r6]
	ldr r0, [sp, #0x40]
	strb r2, [r0]
	b _081BF8F2
	.align 2, 0
_081BF79C: .4byte 0x00000222
_081BF7A0:
	ldr r1, [sp, #0x18]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r1, r2
	ldr r1, [r0]
	movs r0, #1
	ldr r4, [sp, #0x44]
	strb r0, [r4]
	ldr r2, [sp, #0x3c]
	strb r5, [r2]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r2, [sp, #0x28]
	str r1, [r2]
	ldr r4, [sp, #0x58]
	strh r3, [r4]
	movs r1, #5
	ldr r2, [sp, #0x30]
	strb r5, [r2]
	ldr r4, [sp, #0x34]
	strb r5, [r4]
	ldr r5, [sp, #0x38]
	strb r1, [r5]
	ldr r1, [sp, #0x4c]
	str r3, [r1]
	ldr r2, [sp, #0x40]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BF806
	cmp r1, #0
	blt _081BF806
	ldr r0, _081BF80C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BF806
	ldr r0, _081BF810 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BF814
_081BF806:
	movs r4, #0
	b _081BF822
	.align 2, 0
_081BF80C: .4byte 0x030046A8
_081BF810: .4byte 0x030046AC
_081BF814:
	ldr r0, _081BF834 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BF822:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BF838
	adds r0, #4
	b _081BF844
	.align 2, 0
_081BF834: .4byte 0x030046A4
_081BF838:
	ldr r0, _081BF858 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BF844:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BF85C
	cmp r2, #2
	beq _081BF860
	b _081BF864
	.align 2, 0
_081BF858: .4byte 0x030046A4
_081BF85C:
	ldrb r0, [r5, #4]
	b _081BF862
_081BF860:
	ldrb r0, [r5]
_081BF862:
	subs r1, r1, r0
_081BF864:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BF88C
	cmp r1, #0
	blt _081BF88C
	ldr r0, _081BF890 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BF88C
	ldr r0, _081BF894 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BF898
_081BF88C:
	movs r4, #0
	b _081BF8A6
	.align 2, 0
_081BF890: .4byte 0x030046A8
_081BF894: .4byte 0x030046AC
_081BF898:
	ldr r0, _081BF8B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BF8A6:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BF8BC
	adds r0, #4
	b _081BF8C8
	.align 2, 0
_081BF8B8: .4byte 0x030046A4
_081BF8BC:
	ldr r0, _081BF8DC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BF8C8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081BF8E0
	cmp r3, #2
	beq _081BF8E4
	b _081BF8E8
	.align 2, 0
_081BF8DC: .4byte 0x030046A4
_081BF8E0:
	ldrb r0, [r5, #4]
	b _081BF8E6
_081BF8E4:
	ldrb r0, [r5]
_081BF8E6:
	subs r2, r2, r0
_081BF8E8:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081BF8F2:
	ldr r4, [sp, #0x18]
	ldrb r4, [r4, #5]
	str r4, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	ldr r6, [sp, #0x18]
	adds r1, r6, r1
	str r1, [sp, #0x48]
	cmp r0, #0
	bne _081BFA0A
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081BF920
	movs r0, #1
	b _081BF922
_081BF920:
	movs r0, #0
_081BF922:
	ldr r4, _081BFA1C @ =0x00000482
	ldr r3, [sp, #0x18]
	adds r4, r3, r4
	str r4, [sp, #0x48]
	cmp r0, #0
	bne _081BFA0A
	movs r3, #0
	ldr r5, [sp, #0x18]
	movs r6, #0xa8
	lsls r6, r6, #3
	adds r5, r5, r6
	mov sb, r5
	ldr r0, [sp, #0x18]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r0, r1
	mov sl, r0
	ldr r2, [sp, #0x18]
	ldr r4, _081BFA20 @ =0x0000054F
	adds r2, r2, r4
	mov ip, r2
	adds r6, #0xc
	ldr r5, [sp, #0x18]
	adds r6, r5, r6
	str r6, [sp, #0x5c]
	ldr r0, _081BFA24 @ =0x0000054D
	adds r0, r5, r0
	str r0, [sp, #0x60]
	adds r1, #6
	adds r1, r5, r1
	str r1, [sp, #0x64]
	ldr r2, _081BFA28 @ =0x00000541
	adds r2, r5, r2
	str r2, [sp, #0x50]
	adds r4, #0x6d
	adds r4, r5, r4
	str r4, [sp, #0x2c]
	ldr r6, _081BFA2C @ =0x00000542
	adds r6, r5, r6
	str r6, [sp, #0x54]
	ldr r6, _081BFA30 @ =0x0203B400
	ldr r1, _081BFA34 @ =0x030046B8
	ldr r5, _081BFA38 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081BF97C:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _081BF99A
	adds r3, #1
	cmp r3, #3
	ble _081BF97C
	mov r0, r8
_081BF99A:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x28]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x68]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x30]
	ldrb r0, [r1]
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	ldr r5, [sp, #0x60]
	strb r0, [r5]
	ldr r6, [sp, #0x38]
	ldrb r0, [r6]
	ldr r1, [sp, #0x64]
	strb r0, [r1]
	add r2, sp, #0x24
	ldrb r4, [r2]
	ldr r2, [sp, #0x50]
	strb r4, [r2]
	ldr r4, [sp, #0x2c]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r6, [sp, #0x3c]
	strb r3, [r6]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r5, [sp, #0x28]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x58]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x30]
	strb r0, [r4]
	ldr r5, [sp, #0x34]
	strb r1, [r5]
	ldr r6, [sp, #0x38]
	strb r2, [r6]
	ldr r0, [sp, #0x4c]
	str r3, [r0]
	ldr r2, [sp, #0x40]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x54]
	strb r0, [r3]
_081BFA0A:
	ldr r0, [sp, #0x18]
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x48]
	strh r0, [r4]
	movs r0, #0
	b _081BFB1A
	.align 2, 0
_081BFA1C: .4byte 0x00000482
_081BFA20: .4byte 0x0000054F
_081BFA24: .4byte 0x0000054D
_081BFA28: .4byte 0x00000541
_081BFA2C: .4byte 0x00000542
_081BFA30: .4byte 0x0203B400
_081BFA34: .4byte 0x030046B8
_081BFA38: .4byte 0x000003FF
_081BFA3C:
	add r6, sp, #0x10
	ldr r0, _081BFA7C @ =0x030046A4
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
	cmp r0, #0
	beq _081BFA80
	adds r0, #4
	b _081BFA8C
	.align 2, 0
_081BFA7C: .4byte 0x030046A4
_081BFA80:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081BFA8C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, [sp, #0x18]
	ldr r6, _081BFAC4 @ =0x000004A4
	adds r0, r5, r6
	ldr r4, [r0]
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	add r2, sp, #0x10
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081BFACC
	ldr r0, _081BFAC8 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081BFAF6
	.align 2, 0
_081BFAC4: .4byte 0x000004A4
_081BFAC8: .4byte 0xFFFFFDFF
_081BFACC:
	adds r0, r4, #0
	adds r1, r5, #0
	add r2, sp, #0x10
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081BFAEC
	cmp r0, #2
	beq _081BFAE8
	ldr r0, [sp, #0x18]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BFAE8:
	movs r0, #1
	b _081BFAF8
_081BFAEC:
	ldr r0, _081BFB10 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081BFAF6:
	movs r0, #0
_081BFAF8:
	cmp r0, #0
	bne _081BFB18
	ldr r4, [sp, #0x18]
	ldr r5, _081BFB14 @ =0x000005C4
	adds r0, r4, r5
	ldr r1, [r0]
	adds r0, r4, #0
_081BFB06:
	bl _call_via_r1
	movs r0, #0
	b _081BFB1A
	.align 2, 0
_081BFB10: .4byte 0xFFFFFDFF
_081BFB14: .4byte 0x000005C4
_081BFB18:
	movs r0, #1
_081BFB1A:
	cmp r0, #0
	bne _081BFB20
	b _081BFCB2
_081BFB20:
	ldr r6, [sp, #0x18]
	ldr r0, _081BFB2C @ =0x00000482
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	b _081BFC9C
	.align 2, 0
_081BFB2C: .4byte 0x00000482
_081BFB30:
	movs r2, #0x10
	ldr r3, [sp, #0x18]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r5, _081BFBB4 @ =0x00000482
	adds r0, r3, r5
	movs r6, #1
	strh r6, [r0]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	ldr r5, [sp, #0x18]
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081BFBB8 @ =0x00000551
	adds r0, r5, r3
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r5, r1
	ldr r5, [r0]
	ldr r2, [sp, #0x18]
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081BFBB0
	cmp r1, #0
	blt _081BFBB0
	ldr r0, _081BFBBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081BFBB0
	ldr r0, _081BFBC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081BFBC4
_081BFBB0:
	movs r4, #0
	b _081BFBD2
	.align 2, 0
_081BFBB4: .4byte 0x00000482
_081BFBB8: .4byte 0x00000551
_081BFBBC: .4byte 0x030046A8
_081BFBC0: .4byte 0x030046AC
_081BFBC4:
	ldr r0, _081BFBE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081BFBD2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081BFBE8
	adds r0, #4
	b _081BFBF4
	.align 2, 0
_081BFBE4: .4byte 0x030046A4
_081BFBE8:
	ldr r0, _081BFC08 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081BFBF4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081BFC0C
	cmp r2, #2
	beq _081BFC10
	b _081BFC14
	.align 2, 0
_081BFC08: .4byte 0x030046A4
_081BFC0C:
	ldrb r0, [r5, #4]
	b _081BFC12
_081BFC10:
	ldrb r0, [r5]
_081BFC12:
	subs r1, r1, r0
_081BFC14:
	strh r1, [r5, #2]
	ldr r3, [sp, #0x18]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r2, r3, r4
	ldr r1, [r2]
	movs r0, #1
	strh r0, [r1, #6]
	ldr r5, _081BFC4C @ =0x000004A4
	adds r0, r3, r5
	ldr r4, [r0]
	adds r5, r3, #0
	adds r5, #8
	ldr r6, [r2]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081BFC54
	ldr r0, _081BFC50 @ =0xFFFFFDFF
	mov r6, sl
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _081BFC7E
	.align 2, 0
_081BFC4C: .4byte 0x000004A4
_081BFC50: .4byte 0xFFFFFDFF
_081BFC54:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081BFC74
	cmp r0, #2
	beq _081BFC70
	ldr r0, [sp, #0x18]
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081BFC70:
	movs r0, #1
	b _081BFC80
_081BFC74:
	ldr r0, _081BFC94 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081BFC7E:
	movs r0, #0
_081BFC80:
	cmp r0, #0
	bne _081BFC9C
	ldr r3, [sp, #0x18]
	ldr r4, _081BFC98 @ =0x000005C4
	adds r0, r3, r4
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
	b _081BFCB2
	.align 2, 0
_081BFC94: .4byte 0xFFFFFDFF
_081BFC98: .4byte 0x000005C4
_081BFC9C:
	ldr r5, _081BFCC4 @ =0x000006BA
	adds r1, r7, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r6, [sp, #0x18]
	ldr r0, _081BFCC8 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081BFCB2:
	add sp, #0x6c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081BFCC4: .4byte 0x000006BA
_081BFCC8: .4byte 0x00000484
