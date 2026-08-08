	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r6, #0
	adds r7, r1, #0
	ldr r0, _082310F8 @ =0x0000A635
	cmp r4, r0
	beq _08231190
	cmp r4, r0
	bgt _08231118
	ldr r0, _082310FC @ =0x000092B3
	cmp r4, r0
	beq _08231160
	cmp r4, r0
	bgt _08231100
	subs r0, #0x85
	cmp r4, r0
	beq _08231150
	b _082311E6
	.align 2, 0
_082310F8: .4byte 0x0000A635
_082310FC: .4byte 0x000092B3
_08231100:
	ldr r0, _08231110 @ =0x000098F5
	cmp r4, r0
	beq _08231180
	ldr r0, _08231114 @ =0x00009B1B
	cmp r4, r0
	beq _08231170
	b _082311E6
	.align 2, 0
_08231110: .4byte 0x000098F5
_08231114: .4byte 0x00009B1B
_08231118:
	ldr r0, _08231130 @ =0x0000CB05
	cmp r4, r0
	beq _082311C0
	cmp r4, r0
	bgt _0823113C
	ldr r0, _08231134 @ =0x0000AE6C
	cmp r4, r0
	beq _082311A0
	ldr r0, _08231138 @ =0x0000C091
	cmp r4, r0
	beq _082311B0
	b _082311E6
	.align 2, 0
_08231130: .4byte 0x0000CB05
_08231134: .4byte 0x0000AE6C
_08231138: .4byte 0x0000C091
_0823113C:
	ldr r0, _0823114C @ =0x0000CEAA
	cmp r4, r0
	beq _082311E0
	adds r0, #0x45
	cmp r4, r0
	beq _082311D0
	b _082311E6
	.align 2, 0
_0823114C: .4byte 0x0000CEAA
_08231150:
	ldr r4, _08231158 @ =0x00009225
	ldr r1, _0823115C @ =0x00005130
	b _082311E4
	.align 2, 0
_08231158: .4byte 0x00009225
_0823115C: .4byte 0x00005130
_08231160:
	ldr r4, _08231168 @ =0x00009305
	ldr r1, _0823116C @ =0x0000D710
	b _082311E4
	.align 2, 0
_08231168: .4byte 0x00009305
_0823116C: .4byte 0x0000D710
_08231170:
	ldr r4, _08231178 @ =0x00009A65
	ldr r1, _0823117C @ =0x00004679
	b _082311E4
	.align 2, 0
_08231178: .4byte 0x00009A65
_0823117C: .4byte 0x00004679
_08231180:
	ldr r4, _08231188 @ =0x00009B05
	ldr r1, _0823118C @ =0x00002117
	b _082311E4
	.align 2, 0
_08231188: .4byte 0x00009B05
_0823118C: .4byte 0x00002117
_08231190:
	ldr r4, _08231198 @ =0x0000A705
	ldr r1, _0823119C @ =0x00006D24
	b _082311E4
	.align 2, 0
_08231198: .4byte 0x0000A705
_0823119C: .4byte 0x00006D24
_082311A0:
	ldr r4, _082311A8 @ =0x0000AF05
	ldr r1, _082311AC @ =0x0000AC2C
	b _082311E4
	.align 2, 0
_082311A8: .4byte 0x0000AF05
_082311AC: .4byte 0x0000AC2C
_082311B0:
	ldr r4, _082311B8 @ =0x0000C305
	ldr r1, _082311BC @ =0x0000E53E
	b _082311E4
	.align 2, 0
_082311B8: .4byte 0x0000C305
_082311BC: .4byte 0x0000E53E
_082311C0:
	ldr r4, _082311C8 @ =0x0000C8E5
	ldr r1, _082311CC @ =0x00005F29
	b _082311E4
	.align 2, 0
_082311C8: .4byte 0x0000C8E5
_082311CC: .4byte 0x00005F29
_082311D0:
	ldr r4, _082311D8 @ =0x0000CEE5
	ldr r1, _082311DC @ =0x00004F2D
	b _082311E4
	.align 2, 0
_082311D8: .4byte 0x0000CEE5
_082311DC: .4byte 0x00004F2D
_082311E0:
	ldr r4, _0823120C @ =0x0000CF05
	ldr r1, _08231210 @ =0x00000A4D
_082311E4:
	movs r6, #1
_082311E6:
	lsls r5, r4, #0x10
	orrs r5, r1
	ldr r1, _08231214 @ =0x085B0D90
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0xa
	bl FUN_08231094
	cmp r6, #1
	bne _08231206
	adds r2, r7, #0
	lsls r3, r5, #0x10
	lsrs r3, r3, #0x10
	adds r1, r4, #0
	bl FUN_0823103c
_08231206:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823120C: .4byte 0x0000CF05
_08231210: .4byte 0x00000A4D
_08231214: .4byte 0x085B0D90
