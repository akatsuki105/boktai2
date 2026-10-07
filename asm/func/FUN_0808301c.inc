	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #8
	beq _08083038
	adds r0, r5, #0
	movs r1, #8
	movs r2, #0
	bl FUN_08080e0c
_08083038:
	ldr r2, _08083050 @ =0x00000951
	adds r0, r5, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _08083054 @ =0x0000037D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08083058
	cmp r0, #1
	beq _08083076
	b _080831CC
	.align 2, 0
_08083050: .4byte 0x00000951
_08083054: .4byte 0x0000037D
_08083058:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _0808306A
	b _080831CC
_0808306A:
	adds r0, r5, #0
	movs r1, #8
	movs r2, #1
	bl FUN_08080e0c
	b _080831CC
_08083076:
	bl FUN_08084754
	ldr r1, _08083098 @ =0x0000095E
	adds r0, r5, r1
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r2, _0808309C @ =0x0000037E
	adds r0, r5, r2
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080830A0
	movs r3, #0x96
	lsls r3, r3, #4
	adds r0, r5, r3
	strh r1, [r0]
	b _080830AC
	.align 2, 0
_08083098: .4byte 0x0000095E
_0808309C: .4byte 0x0000037E
_080830A0:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	strh r0, [r1]
_080830AC:
	ldr r3, _08083150 @ =0x0000037E
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _080830C2
	movs r0, #0
	strh r0, [r1]
_080830C2:
	ldr r1, _08083154 @ =0x000001E3
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	bl FUN_080230c4
	adds r6, r0, #0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r2, #0x2c
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080830E2
	rsbs r0, r0, #0
_080830E2:
	adds r3, r0, #0
	movs r0, #4
	ldrsh r1, [r6, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080830F4
	rsbs r1, r1, #0
_080830F4:
	adds r2, r1, #0
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	cmp r3, #0xbf
	bgt _0808310A
	cmp r2, #0xbf
	ble _08083112
_0808310A:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080831CC
_08083112:
	mov r4, sp
	mov r0, sp
	bl FUN_08084734
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r0, [r6, r3]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r6, r2]
	subs r2, r1, r0
	adds r0, r3, #0
	adds r1, r2, #0
	bl ArcTan2_8
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	movs r6, #0
	cmp r0, #1
	beq _08083162
	cmp r0, #1
	bgt _08083158
	cmp r0, #0
	beq _0808315E
	b _08083168
	.align 2, 0
_08083150: .4byte 0x0000037E
_08083154: .4byte 0x000001E3
_08083158:
	cmp r0, #2
	beq _08083166
	b _08083168
_0808315E:
	movs r6, #3
	b _08083168
_08083162:
	movs r6, #1
	b _08083168
_08083166:
	movs r6, #2
_08083168:
	ldr r3, _080831D4 @ =0x000004A6
	adds r7, r5, r3
	ldrb r0, [r7]
	adds r0, #3
	movs r1, #3
	ands r0, r1
	cmp r0, r6
	beq _080831C2
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x2c
	lsls r4, r6, #3
	subs r3, #0x2e
	adds r2, r4, r3
	adds r2, r5, r2
	bl FUN_08235f40
	cmp r0, #0
	beq _080831C2
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #8
	strb r0, [r1]
	adds r0, r5, r4
	ldr r1, _080831D8 @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _080831DC @ =0x00000471
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r6, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r7]
	movs r0, #0x1e
	bl FUN_08084798
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_080831C2:
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
_080831CC:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080831D4: .4byte 0x000004A6
_080831D8: .4byte 0x0000047E
_080831DC: .4byte 0x00000471
