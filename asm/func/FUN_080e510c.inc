	push {lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	subs r0, r1, #1
	cmp r0, #0x1d
	bls _080E5122
	b _080E537E
_080E5122:
	lsls r0, r0, #2
	ldr r1, _080E512C @ =_080E5130
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E512C: .4byte _080E5130
_080E5130: @ jump table
	.4byte _080E51D8 @ case 0
	.4byte _080E537E @ case 1
	.4byte _080E5210 @ case 2
	.4byte _080E51A8 @ case 3
	.4byte _080E5334 @ case 4
	.4byte _080E5334 @ case 5
	.4byte _080E5334 @ case 6
	.4byte _080E5334 @ case 7
	.4byte _080E537E @ case 8
	.4byte _080E52A0 @ case 9
	.4byte _080E5304 @ case 10
	.4byte _080E537E @ case 11
	.4byte _080E537E @ case 12
	.4byte _080E537E @ case 13
	.4byte _080E537E @ case 14
	.4byte _080E537E @ case 15
	.4byte _080E537E @ case 16
	.4byte _080E537E @ case 17
	.4byte _080E537E @ case 18
	.4byte _080E537E @ case 19
	.4byte _080E52D8 @ case 20
	.4byte _080E537E @ case 21
	.4byte _080E534C @ case 22
	.4byte _080E537E @ case 23
	.4byte _080E537E @ case 24
	.4byte _080E537E @ case 25
	.4byte _080E537E @ case 26
	.4byte _080E51A8 @ case 27
	.4byte _080E537E @ case 28
	.4byte _080E5210 @ case 29
_080E51A8:
	cmp r3, #1
	beq _080E51C8
	cmp r3, #1
	bgt _080E51B6
	cmp r3, #0
	beq _080E51C0
	b _080E537E
_080E51B6:
	cmp r3, #2
	beq _080E51D0
	cmp r3, #3
	beq _080E51C0
	b _080E537E
_080E51C0:
	movs r0, #0xf0
	bl PlaySound_082406e0
	b _080E537E
_080E51C8:
	movs r0, #0xef
	bl PlaySound_082406e0
	b _080E537E
_080E51D0:
	movs r0, #0xf1
	bl PlaySound_082406e0
	b _080E537E
_080E51D8:
	cmp r3, #1
	beq _080E51FC
	cmp r3, #1
	bgt _080E51E6
	cmp r3, #0
	beq _080E51F0
	b _080E537E
_080E51E6:
	cmp r3, #2
	beq _080E5206
	cmp r3, #3
	beq _080E51F0
	b _080E537E
_080E51F0:
	ldr r0, _080E51F8 @ =0x00000103
	bl PlaySound_082406e0
	b _080E537E
	.align 2, 0
_080E51F8: .4byte 0x00000103
_080E51FC:
	movs r0, #0x81
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E537E
_080E5206:
	movs r0, #0x82
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E537E
_080E5210:
	cmp r3, #1
	beq _080E524E
	cmp r3, #1
	bgt _080E521E
	cmp r3, #0
	beq _080E5228
	b _080E537E
_080E521E:
	cmp r3, #2
	beq _080E5278
	cmp r3, #3
	beq _080E5228
	b _080E537E
_080E5228:
	cmp r2, #3
	beq _080E5244
	cmp r2, #3
	bgt _080E523E
	cmp r2, #1
	ble _080E5236
	b _080E537E
_080E5236:
	cmp r2, #0
	bge _080E523C
	b _080E537E
_080E523C:
	b _080E5244
_080E523E:
	cmp r2, #5
	beq _080E5244
	b _080E537E
_080E5244:
	movs r0, #0xc3
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E537E
_080E524E:
	cmp r2, #3
	beq _080E526A
	cmp r2, #3
	bgt _080E5264
	cmp r2, #1
	ble _080E525C
	b _080E537E
_080E525C:
	cmp r2, #0
	bge _080E5262
	b _080E537E
_080E5262:
	b _080E526A
_080E5264:
	cmp r2, #5
	beq _080E526A
	b _080E537E
_080E526A:
	ldr r0, _080E5274 @ =0x00000185
	bl PlaySound_082406e0
	b _080E537E
	.align 2, 0
_080E5274: .4byte 0x00000185
_080E5278:
	cmp r2, #3
	beq _080E5294
	cmp r2, #3
	bgt _080E528E
	cmp r2, #1
	ble _080E5286
	b _080E537E
_080E5286:
	cmp r2, #0
	bge _080E528C
	b _080E537E
_080E528C:
	b _080E5294
_080E528E:
	cmp r2, #5
	beq _080E5294
	b _080E537E
_080E5294:
	ldr r0, _080E529C @ =0x00000187
	bl PlaySound_082406e0
	b _080E537E
	.align 2, 0
_080E529C: .4byte 0x00000187
_080E52A0:
	cmp r3, #1
	beq _080E52C0
	cmp r3, #1
	bgt _080E52AE
	cmp r3, #0
	beq _080E52B6
	b _080E537E
_080E52AE:
	cmp r3, #2
	beq _080E52CC
	cmp r3, #3
	bne _080E537E
_080E52B6:
	movs r0, #0xe4
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E537E
_080E52C0:
	ldr r0, _080E52C8 @ =0x000001C7
	bl PlaySound_082406e0
	b _080E537E
	.align 2, 0
_080E52C8: .4byte 0x000001C7
_080E52CC:
	ldr r0, _080E52D4 @ =0x000001C9
	bl PlaySound_082406e0
	b _080E537E
	.align 2, 0
_080E52D4: .4byte 0x000001C9
_080E52D8:
	cmp r3, #1
	beq _080E52F8
	cmp r3, #1
	bgt _080E52E6
	cmp r3, #0
	beq _080E52EE
	b _080E537E
_080E52E6:
	cmp r3, #2
	beq _080E5340
	cmp r3, #3
	bne _080E537E
_080E52EE:
	movs r0, #0xe9
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080E537E
_080E52F8:
	ldr r0, _080E5300 @ =0x000003A3
	bl PlaySound_082406e0
	b _080E537E
	.align 2, 0
_080E5300: .4byte 0x000003A3
_080E5304:
	cmp r3, #1
	beq _080E531A
	cmp r3, #1
	bgt _080E5312
	cmp r3, #0
	beq _080E531A
	b _080E537E
_080E5312:
	cmp r3, #2
	beq _080E5328
	cmp r3, #3
	bne _080E537E
_080E531A:
	ldr r0, _080E5324 @ =0x00000271
	bl PlaySound_082406e0
	b _080E537E
	.align 2, 0
_080E5324: .4byte 0x00000271
_080E5328:
	ldr r0, _080E5330 @ =0x00000272
	bl PlaySound_082406e0
	b _080E537E
	.align 2, 0
_080E5330: .4byte 0x00000272
_080E5334:
	cmp r3, #1
	beq _080E536C
	cmp r3, #1
	ble _080E5354
	cmp r3, #2
	bne _080E535E
_080E5340:
	ldr r0, _080E5348 @ =0x0000013B
	bl PlaySound_082406e0
	b _080E537E
	.align 2, 0
_080E5348: .4byte 0x0000013B
_080E534C:
	cmp r3, #1
	beq _080E536C
	cmp r3, #1
	bgt _080E535A
_080E5354:
	cmp r3, #0
	beq _080E5362
	b _080E537E
_080E535A:
	cmp r3, #2
	beq _080E5378
_080E535E:
	cmp r3, #3
	bne _080E537E
_080E5362:
	movs r0, #0x9d
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E537E
_080E536C:
	ldr r0, _080E5374 @ =0x00000139
	bl PlaySound_082406e0
	b _080E537E
	.align 2, 0
_080E5374: .4byte 0x00000139
_080E5378:
	ldr r0, _080E5384 @ =0x0000013B
	bl PlaySound_082406e0
_080E537E:
	pop {r0}
	bx r0
	.align 2, 0
_080E5384: .4byte 0x0000013B
