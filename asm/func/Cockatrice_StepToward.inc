	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldr r7, [sp, #0x18]
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	subs r2, r1, r0
	cmp r2, #0
	beq _0815BF8E
	adds r0, r2, #0
	cmp r2, #0
	bge _0815BF80
	rsbs r0, r2, #0
_0815BF80:
	cmp r0, r3
	bls _0815BF88
	movs r1, #0
	b _0815BF98
_0815BF88:
	ldrh r0, [r5]
	adds r0, r0, r2
	strh r0, [r5]
_0815BF8E:
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r4, #4
	ldrsh r0, [r5, r4]
	subs r1, r1, r0
_0815BF98:
	adds r0, r2, #0
	cmp r2, #0
	bge _0815BFA0
	rsbs r0, r2, #0
_0815BFA0:
	cmp r0, r3
	bhi _0815BFC2
	adds r3, r1, #0
	cmp r1, #0
	bge _0815BFAC
	rsbs r3, r1, #0
_0815BFAC:
	ldr r0, [sp, #0x14]
	cmp r3, r0
	bhi _0815BFC2
	ldrh r0, [r5]
	adds r0, r0, r2
	strh r0, [r5]
	ldrh r0, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	movs r0, #1
	b _0815C056
_0815BFC2:
	cmp r2, #0
	bne _0815BFCA
	cmp r1, #0
	beq _0815C054
_0815BFCA:
	adds r0, r2, #0
	bl ArcTan2_8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	lsls r4, r0, #6
	strb r4, [r6]
	ldr r1, _0815BFFC @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0815C000
	asrs r0, r0, #0x10
	b _0815C006
	.align 2, 0
_0815BFFC: .4byte gSineTable
_0815C000:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0815C006:
	adds r3, r0, #0
	ldr r0, _0815C01C @ =gSineTable
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0815C020
	asrs r0, r0, #0x10
	b _0815C026
	.align 2, 0
_0815C01C: .4byte gSineTable
_0815C020:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0815C026:
	adds r2, r3, #0
	cmp r3, #0
	bge _0815C02E
	rsbs r2, r3, #0
_0815C02E:
	movs r1, #0
	cmp r2, #2
	ble _0815C036
	adds r1, r3, #0
_0815C036:
	adds r3, r1, #0
	adds r2, r0, #0
	cmp r0, #0
	bge _0815C040
	rsbs r2, r0, #0
_0815C040:
	movs r1, #0
	cmp r2, #2
	ble _0815C048
	adds r1, r0, #0
_0815C048:
	ldrh r0, [r5]
	adds r0, r0, r3
	strh r0, [r5]
	ldrh r0, [r5, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
_0815C054:
	movs r0, #0
_0815C056:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
