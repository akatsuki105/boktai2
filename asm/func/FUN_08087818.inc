	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xff
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _0808782E
	adds r0, #1
	strh r0, [r1]
	b _08087968
_0808782E:
	ldr r1, _08087878 @ =0x000001F5
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0808783A
	b _08087968
_0808783A:
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08087848
	b _08087968
_08087848:
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r0, #0
	cmp r2, #0
	blt _08087872
	cmp r1, #0
	blt _08087872
	ldr r0, _0808787C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087872
	ldr r0, _08087880 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087884
_08087872:
	movs r4, #0
	b _08087892
	.align 2, 0
_08087878: .4byte 0x000001F5
_0808787C: .4byte 0x030046A8
_08087880: .4byte 0x030046AC
_08087884:
	ldr r0, _080878A4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087892:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080878A8
	adds r0, #4
	b _080878B4
	.align 2, 0
_080878A4: .4byte 0x030046A4
_080878A8:
	ldr r0, _080878F0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080878B4:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _08087964
	ldr r1, _080878F4 @ =0x000001F5
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08087968
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080878EC
	cmp r1, #0
	blt _080878EC
	ldr r0, _080878F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080878EC
	ldr r0, _080878FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087900
_080878EC:
	movs r4, #0
	b _0808790E
	.align 2, 0
_080878F0: .4byte 0x030046A4
_080878F4: .4byte 0x000001F5
_080878F8: .4byte 0x030046A8
_080878FC: .4byte 0x030046AC
_08087900:
	ldr r0, _08087920 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808790E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08087924
	adds r0, #4
	b _08087930
	.align 2, 0
_08087920: .4byte 0x030046A4
_08087924:
	ldr r0, _08087944 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087930:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087948
	cmp r2, #2
	beq _0808794C
	b _08087950
	.align 2, 0
_08087944: .4byte 0x030046A4
_08087948:
	ldrb r0, [r5, #4]
	b _0808794E
_0808794C:
	ldrb r0, [r5]
_0808794E:
	subs r1, r1, r0
_08087950:
	adds r0, r6, #0
	adds r0, #0x4a
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08087960
	rsbs r0, r0, #0
_08087960:
	cmp r0, #0xff
	ble _08087968
_08087964:
	movs r0, #1
	b _0808796A
_08087968:
	movs r0, #0
_0808796A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
