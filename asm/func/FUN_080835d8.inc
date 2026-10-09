	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _080835F8
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08080e0c
_080835F8:
	ldr r2, _08083638 @ =0x00000951
	adds r0, r7, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _0808363C @ =0x000003E6
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0808367E
	movs r4, #0xfa
	lsls r4, r4, #2
	adds r0, r7, r4
	ldrh r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r2]
	ldr r2, _08083640 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r3, r0
	cmp r0, #0
	blt _08083644
	asrs r0, r0, #0xc
	b _0808364A
	.align 2, 0
_08083638: .4byte 0x00000951
_0808363C: .4byte 0x000003E6
_08083640: .4byte 0x085B0A08
_08083644:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808364A:
	strh r0, [r7, #0x34]
	ldr r1, _08083664 @ =0x000003E6
	adds r0, r7, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08083668
	asrs r0, r0, #0xc
	b _0808366E
	.align 2, 0
_08083664: .4byte 0x000003E6
_08083668:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808366E:
	strh r0, [r7, #0x38]
	ldr r3, _08083698 @ =0x000003E6
	adds r2, r7, r3
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
_0808367E:
	ldr r4, _0808369C @ =0x0000037D
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #6
	bls _0808368C
	bl _08083E9C
_0808368C:
	lsls r0, r0, #2
	ldr r1, _080836A0 @ =_080836A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08083698: .4byte 0x000003E6
_0808369C: .4byte 0x0000037D
_080836A0: .4byte _080836A4
_080836A4: @ jump table
	.4byte _080836C0 @ case 0
	.4byte _080836EC @ case 1
	.4byte _08083774 @ case 2
	.4byte _08083800 @ case 3
	.4byte _0808388C @ case 4
	.4byte _08083E44 @ case 5
	.4byte _08083E74 @ case 6
_080836C0:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _080836DE
	bl _08083E9C
_080836DE:
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #1
	bl FUN_08080e0c
	bl _08083E9C
_080836EC:
	ldr r6, _08083754 @ =0x0000037E
	adds r4, r7, r6
	ldrh r0, [r4]
	cmp r0, #0
	bne _080836FC
	ldr r0, _08083758 @ =0x000001F7
	bl PlaySound_082406e0
_080836FC:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _0808375C @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08083720
	b _08083E9C
_08083720:
	ldr r0, _08083760 @ =0x00000402
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08083764 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08083768 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0808376C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r2, _08083770 @ =0x00000403
	adds r1, r7, r2
	strb r0, [r1]
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #2
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083754: .4byte 0x0000037E
_08083758: .4byte 0x000001F7
_0808375C: .4byte 0x000001E3
_08083760: .4byte 0x00000402
_08083764: .4byte 0x030046B8
_08083768: .4byte 0x000003FF
_0808376C: .4byte 0x0203B400
_08083770: .4byte 0x00000403
_08083774:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _080837C0 @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r3, _080837C4 @ =0x0000037E
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2c
	bhi _0808379C
	b _08083E9C
_0808379C:
	ldr r6, _080837C8 @ =0x00000402
	adds r4, r7, r6
	ldr r0, _080837CC @ =0x00000403
	adds r1, r7, r0
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	blo _080837D4
	ldr r0, _080837D0 @ =0x000002E9
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #3
	bl FUN_08080e0c
	b _080837E4
	.align 2, 0
_080837C0: .4byte 0x000001E3
_080837C4: .4byte 0x0000037E
_080837C8: .4byte 0x00000402
_080837CC: .4byte 0x00000403
_080837D0: .4byte 0x000002E9
_080837D4:
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #2
	bl FUN_08080e0c
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_080837E4:
	ldr r2, _080837FC @ =0x0000095E
	adds r1, r7, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r7, r3
	movs r0, #0x20
	strh r0, [r1]
	b _08083E9C
	.align 2, 0
_080837FC: .4byte 0x0000095E
_08083800:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _08083874 @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r4, _08083878 @ =0x0000037E
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _08083828
	b _08083E9C
_08083828:
	ldr r0, _0808387C @ =0x00000366
	bl PlaySound_082406e0
	movs r6, #0xba
	lsls r6, r6, #2
	adds r2, r7, r6
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r3, _08083880 @ =0x00000A8A
	adds r1, r7, r3
	strh r0, [r1]
	ldr r4, _08083884 @ =0x000004A4
	adds r1, r7, r4
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r6, _08083888 @ =0x000004A7
	adds r1, r7, r6
	strb r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_08084734
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #4
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083874: .4byte 0x000001E3
_08083878: .4byte 0x0000037E
_0808387C: .4byte 0x00000366
_08083880: .4byte 0x00000A8A
_08083884: .4byte 0x000004A4
_08083888: .4byte 0x000004A7
_0808388C:
	ldr r2, _080838F8 @ =0x000003E6
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #0x80
	bl PlayerLink_SetFlag35a
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080838AE
	b _08083B48
_080838AE:
	movs r6, #0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, sp, #8
	ldrh r1, [r0]
	adds r1, #0x23
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080838FC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080838F4
	cmp r1, #0
	blt _080838F4
	ldr r0, _08083900 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080838F4
	ldr r0, _08083904 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083908
_080838F4:
	movs r4, #0
	b _08083916
	.align 2, 0
_080838F8: .4byte 0x000003E6
_080838FC: .4byte 0xFFFF0000
_08083900: .4byte 0x030046A8
_08083904: .4byte 0x030046AC
_08083908:
	ldr r0, _08083928 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083916:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0808392C
	adds r0, #4
	b _08083938
	.align 2, 0
_08083928: .4byte 0x030046A4
_0808392C:
	ldr r0, _0808394C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083938:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083950
	cmp r2, #2
	beq _08083954
	b _08083958
	.align 2, 0
_0808394C: .4byte 0x030046A4
_08083950:
	ldrb r0, [r5, #4]
	b _08083956
_08083954:
	ldrb r0, [r5]
_08083956:
	subs r1, r1, r0
_08083958:
	movs r4, #0x2e
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bne _080839FA
	add r0, sp, #8
	ldrh r0, [r0]
	subs r0, #0x46
	add r1, sp, #8
	strh r0, [r1]
	adds r5, r1, #0
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0808398E
	cmp r1, #0
	blt _0808398E
	ldr r0, _08083994 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0808398E
	ldr r0, _08083998 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808399C
_0808398E:
	movs r4, #0
	b _080839AA
	.align 2, 0
_08083994: .4byte 0x030046A8
_08083998: .4byte 0x030046AC
_0808399C:
	ldr r0, _080839BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080839AA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080839C0
	adds r0, #4
	b _080839CC
	.align 2, 0
_080839BC: .4byte 0x030046A4
_080839C0:
	ldr r0, _080839E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080839CC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080839E4
	cmp r2, #2
	beq _080839E8
	b _080839EC
	.align 2, 0
_080839E0: .4byte 0x030046A4
_080839E4:
	ldrb r0, [r5, #4]
	b _080839EA
_080839E8:
	ldrb r0, [r5]
_080839EA:
	subs r1, r1, r0
_080839EC:
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	cmp r1, r0
	beq _080839F6
	movs r6, #1
_080839F6:
	cmp r6, #0
	beq _08083A0A
_080839FA:
	ldr r3, _08083A44 @ =0x000004A7
	adds r1, r7, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r0, #0x80
	subs r0, r0, r2
	strb r0, [r1]
_08083A0A:
	movs r6, #0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, sp, #8
	ldrh r1, [r0, #4]
	adds r1, #0x23
	strh r1, [r0, #4]
	adds r5, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08083A40
	cmp r1, #0
	blt _08083A40
	ldr r0, _08083A48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08083A40
	ldr r0, _08083A4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083A50
_08083A40:
	movs r4, #0
	b _08083A5E
	.align 2, 0
_08083A44: .4byte 0x000004A7
_08083A48: .4byte 0x030046A8
_08083A4C: .4byte 0x030046AC
_08083A50:
	ldr r0, _08083A70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083A5E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08083A74
	adds r0, #4
	b _08083A80
	.align 2, 0
_08083A70: .4byte 0x030046A4
_08083A74:
	ldr r0, _08083A94 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083A80:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083A98
	cmp r2, #2
	beq _08083A9C
	b _08083AA0
	.align 2, 0
_08083A94: .4byte 0x030046A4
_08083A98:
	ldrb r0, [r5, #4]
	b _08083A9E
_08083A9C:
	ldrb r0, [r5]
_08083A9E:
	subs r1, r1, r0
_08083AA0:
	movs r4, #0x2e
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bne _08083B3E
	add r0, sp, #8
	ldrh r1, [r0, #4]
	subs r1, #0x46
	strh r1, [r0, #4]
	adds r5, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08083AD4
	cmp r1, #0
	blt _08083AD4
	ldr r0, _08083AD8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08083AD4
	ldr r0, _08083ADC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083AE0
_08083AD4:
	movs r4, #0
	b _08083AEE
	.align 2, 0
_08083AD8: .4byte 0x030046A8
_08083ADC: .4byte 0x030046AC
_08083AE0:
	ldr r0, _08083B00 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083AEE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08083B04
	adds r0, #4
	b _08083B10
	.align 2, 0
_08083B00: .4byte 0x030046A4
_08083B04:
	ldr r0, _08083B24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083B10:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083B28
	cmp r2, #2
	beq _08083B2C
	b _08083B30
	.align 2, 0
_08083B24: .4byte 0x030046A4
_08083B28:
	ldrb r0, [r5, #4]
	b _08083B2E
_08083B2C:
	ldrb r0, [r5]
_08083B2E:
	subs r1, r1, r0
_08083B30:
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	cmp r1, r0
	beq _08083B3A
	movs r6, #1
_08083B3A:
	cmp r6, #0
	beq _08083B48
_08083B3E:
	ldr r3, _08083BE0 @ =0x000004A7
	adds r1, r7, r3
	ldrb r0, [r1]
	rsbs r0, r0, #0
	strb r0, [r1]
_08083B48:
	ldr r4, _08083BE4 @ =0x0000037E
	adds r0, r7, r4
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _08083BA2
	movs r6, #0xec
	lsls r6, r6, #2
	adds r4, r7, r6
	adds r0, r4, #0
	bl FUN_08084734
	ldr r0, _08083BE8 @ =0x0203B400
	mov r8, r0
	ldr r1, _08083BEC @ =0x030046B8
	mov ip, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r3, _08083BF0 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrh r0, [r4]
	subs r0, #0xff
	ldr r6, _08083BF4 @ =0x000001FF
	adds r5, r6, #0
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r4]
	adds r1, #1
	ands r1, r3
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	subs r3, #0x4b
	adds r2, r7, r3
	ldrh r0, [r2]
	subs r0, #0xff
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_08083BA2:
	movs r4, #0xec
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r2, #0x2c
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #0xed
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	movs r6, #0x30
	ldrsh r2, [r7, r6]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r1, _08083BE0 @ =0x000004A7
	adds r3, r7, r1
	ldrb r2, [r3]
	subs r0, r0, r2
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _08083BF8
	adds r0, r2, #2
	b _08083BFC
	.align 2, 0
_08083BE0: .4byte 0x000004A7
_08083BE4: .4byte 0x0000037E
_08083BE8: .4byte 0x0203B400
_08083BEC: .4byte 0x030046B8
_08083BF0: .4byte 0x000003FF
_08083BF4: .4byte 0x000001FF
_08083BF8:
	adds r0, r2, #0
	adds r0, #0xfe
_08083BFC:
	strb r0, [r3]
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, #0x80
	bls _08083C20
	ldr r6, _08083C1C @ =0x000004A4
	adds r1, r7, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08083C36
	movs r0, #0x20
	b _08083C34
	.align 2, 0
_08083C1C: .4byte 0x000004A4
_08083C20:
	adds r0, r1, #0
	subs r0, #0x61
	cmp r0, #0x3e
	bhi _08083C36
	ldr r0, _08083C58 @ =0x000004A4
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08083C36
	subs r0, #1
_08083C34:
	strh r0, [r1]
_08083C36:
	ldr r2, _08083C5C @ =0x085B0A08
	ldr r1, _08083C60 @ =0x000004A7
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08083C64
	asrs r0, r0, #0xc
	b _08083C6A
	.align 2, 0
_08083C58: .4byte 0x000004A4
_08083C5C: .4byte 0x085B0A08
_08083C60: .4byte 0x000004A7
_08083C64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083C6A:
	strh r0, [r7, #0x34]
	ldr r1, _08083C88 @ =0x085B0A08
	ldr r3, _08083C8C @ =0x000004A7
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08083C90
	asrs r0, r0, #0xc
	b _08083C96
	.align 2, 0
_08083C88: .4byte 0x085B0A08
_08083C8C: .4byte 0x000004A7
_08083C90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083C96:
	strh r0, [r7, #0x38]
	ldr r6, _08083D0C @ =0x00000A8A
	adds r5, r7, r6
	ldrh r0, [r5]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	strh r0, [r5]
	ldr r0, _08083D10 @ =0x000009E4
	adds r2, r7, r0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08083D14 @ =0x000009E6
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	ldrh r1, [r5]
	ldr r3, _08083D18 @ =0x000009CE
	adds r0, r7, r3
	strb r1, [r0]
	ldrh r1, [r5]
	ldr r0, _08083D1C @ =0x0000010F
	subs r0, r0, r1
	movs r4, #0xff
	ands r0, r4
	asrs r0, r0, #5
	movs r6, #0xba
	lsls r6, r6, #2
	adds r1, r7, r6
	strb r0, [r1]
	adds r0, r7, #0
	bl LinkPlayer_SetAnimFacing
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r1, [r5]
	movs r0, #0xd0
	lsls r0, r0, #1
	subs r5, r0, r1
	ands r5, r4
	ldr r1, _08083D20 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08083D24
	asrs r1, r0, #0xc
	b _08083D2A
	.align 2, 0
_08083D0C: .4byte 0x00000A8A
_08083D10: .4byte 0x000009E4
_08083D14: .4byte 0x000009E6
_08083D18: .4byte 0x000009CE
_08083D1C: .4byte 0x0000010F
_08083D20: .4byte 0x085B0A08
_08083D24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08083D2A:
	add r3, sp, #0x10
	ldrh r0, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08083D60 @ =0xFFFF0000
	ldr r2, [sp, #0x10]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0xe6
	lsls r1, r1, #0x10
	ldr r0, _08083D64 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r1, _08083D68 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08083D6C
	asrs r0, r0, #0xc
	b _08083D72
	.align 2, 0
_08083D60: .4byte 0xFFFF0000
_08083D64: .4byte 0x0000FFFF
_08083D68: .4byte 0x085B0A08
_08083D6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083D72:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _08083E2C @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r7, r0
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _08083E30 @ =0x00000A52
	adds r0, r7, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl Hitbox_Register
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _08083E34 @ =0x0000037E
	adds r4, r7, r2
	ldrh r0, [r4]
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	bne _08083DEE
	ldr r2, _08083E38 @ =0x0000FFFF
	str r1, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r6
	str r0, [r1, #4]
	ldr r0, [sp, #0x20]
	ands r0, r6
	movs r3, #0x20
	orrs r0, r3
	ands r0, r2
	str r0, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r6
	orrs r0, r3
	str r0, [r2, #4]
	adds r0, r7, #0
	adds r0, #0x2c
	movs r3, #2
	str r3, [sp]
	movs r3, #4
	str r3, [sp, #4]
	movs r3, #1
	bl FUN_080dbcec
_08083DEE:
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08083E00
	movs r0, #0x81
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08083E00:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08083E3C @ =0x00000403
	adds r1, r7, r3
	ldrb r1, [r1]
	adds r1, #1
	lsls r1, r1, #5
	cmp r0, r1
	blt _08083E9C
	ldr r0, _08083E40 @ =0x00000366
	bl sound_08240740
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #5
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083E2C: .4byte 0xFFFF0000
_08083E30: .4byte 0x00000A52
_08083E34: .4byte 0x0000037E
_08083E38: .4byte 0x0000FFFF
_08083E3C: .4byte 0x00000403
_08083E40: .4byte 0x00000366
_08083E44:
	ldr r1, _08083E6C @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r4, _08083E70 @ =0x0000037E
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08083E9C
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #6
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083E6C: .4byte 0x000001E3
_08083E70: .4byte 0x0000037E
_08083E74:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r6, _08083EA8 @ =0x0000037E
	adds r1, r7, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08083E9C
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08083E9C:
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08083EA8: .4byte 0x0000037E
