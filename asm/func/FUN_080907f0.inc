	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	movs r4, #0
	ldr r1, _08090840 @ =0x030044E0
	ldrh r2, [r1]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _080908A0
	adds r0, r6, #0
	bl FUN_08090724
	adds r4, r0, #0
	cmp r4, #0
	bne _0809081A
	b _0809090C
_0809081A:
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r1, _08090844 @ =0x00004038
	adds r0, r6, r1
	ldr r2, _08090848 @ =0x00004050
	adds r1, r6, r2
	ldrb r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08090850
	ldr r3, _0809084C @ =0x00002BEC
	adds r0, r6, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _0809085A
	.align 2, 0
_08090840: .4byte 0x030044E0
_08090844: .4byte 0x00004038
_08090848: .4byte 0x00004050
_0809084C: .4byte 0x00002BEC
_08090850:
	ldr r0, _08090878 @ =0x00002BEC
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_0809085A:
	ldr r1, _0809087C @ =0x00004038
	adds r0, r6, r1
	ldr r2, _08090880 @ =0x00004056
	adds r1, r6, r2
	ldrb r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08090888
	ldr r3, _08090884 @ =0x00002C4C
	adds r0, r6, r3
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08090892
	.align 2, 0
_08090878: .4byte 0x00002BEC
_0809087C: .4byte 0x00004038
_08090880: .4byte 0x00004056
_08090884: .4byte 0x00002C4C
_08090888:
	ldr r1, _0809089C @ =0x00002C4C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08090892:
	str r1, [r0]
	adds r0, r6, #0
	bl FUN_0808fbf4
	b _0809090C
	.align 2, 0
_0809089C: .4byte 0x00002C4C
_080908A0:
	ldr r1, _080908C0 @ =0x00004039
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080908AC
	b _080909BE
_080908AC:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _080908C8
	ldr r2, _080908C4 @ =0x00004040
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #2
	b _080908D8
	.align 2, 0
_080908C0: .4byte 0x00004039
_080908C4: .4byte 0x00004040
_080908C8:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080908DC
	ldr r0, _080908F0 @ =0x00004040
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #2
_080908D8:
	strh r0, [r1]
	movs r4, #1
_080908DC:
	ldrh r1, [r3]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080908F8
	ldr r2, _080908F4 @ =0x00004042
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #2
	b _08090908
	.align 2, 0
_080908F0: .4byte 0x00004040
_080908F4: .4byte 0x00004042
_080908F8:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0809090C
	ldr r3, _080909D0 @ =0x00004042
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #2
_08090908:
	strh r0, [r1]
	movs r4, #1
_0809090C:
	ldr r1, _080909D4 @ =0x00004039
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080909BE
	cmp r4, #0
	beq _080909BE
	adds r0, r6, #0
	bl FUN_08090040
	ldr r2, _080909D8 @ =0x00004040
	adds r0, r6, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r2, #0xc
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r7, r1, r0
	ldr r1, _080909D0 @ =0x00004042
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _080909DC @ =0x0000404E
	adds r0, r6, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	mov r8, r1
	asrs r5, r7, #3
	asrs r4, r1, #3
	movs r0, #2
	rsbs r0, r0, #0
	ands r4, r0
	str r1, [sp]
	movs r0, #1
	adds r1, r5, #0
	adds r2, r4, #0
	adds r3, r7, #0
	bl Video_GenerateBGMap
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0808fe7c
	ldr r3, _080909E0 @ =0x00002BEC
	adds r0, r6, r3
	ldr r0, [r0]
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne _08090994
	ldr r1, _080909E4 @ =0x00004052
	adds r0, r6, r1
	ldrh r0, [r0]
	subs r0, r0, r7
	adds r3, #0x18
	adds r1, r6, r3
	strh r0, [r1]
	ldr r1, _080909E8 @ =0x00004054
	adds r0, r6, r1
	ldrh r0, [r0]
	mov r3, r8
	subs r0, r0, r3
	ldr r3, _080909EC @ =0x00002C06
	adds r1, r6, r3
	strh r0, [r1]
_08090994:
	ldr r1, _080909F0 @ =0x00002C4C
	adds r0, r6, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	bne _080909BE
	ldr r2, _080909F4 @ =0x00004058
	adds r0, r6, r2
	ldrh r0, [r0]
	subs r0, r0, r7
	ldr r3, _080909F8 @ =0x00002C64
	adds r1, r6, r3
	strh r0, [r1]
	ldr r1, _080909FC @ =0x0000405A
	adds r0, r6, r1
	ldrh r0, [r0]
	mov r2, r8
	subs r0, r0, r2
	adds r3, #2
	adds r1, r6, r3
	strh r0, [r1]
_080909BE:
	adds r0, r6, #0
	bl FUN_08090120
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080909D0: .4byte 0x00004042
_080909D4: .4byte 0x00004039
_080909D8: .4byte 0x00004040
_080909DC: .4byte 0x0000404E
_080909E0: .4byte 0x00002BEC
_080909E4: .4byte 0x00004052
_080909E8: .4byte 0x00004054
_080909EC: .4byte 0x00002C06
_080909F0: .4byte 0x00002C4C
_080909F4: .4byte 0x00004058
_080909F8: .4byte 0x00002C64
_080909FC: .4byte 0x0000405A
