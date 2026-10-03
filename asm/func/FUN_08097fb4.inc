	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	cmp r1, #0
	bne _08097FC4
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	b _0809809E
_08097FC4:
	movs r7, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _0809807A
	ldr r0, _08098034 @ =0x00003AEE
	adds r5, r3, r0
	ldr r2, _08098038 @ =0x00003AEB
	adds r4, r3, r2
	ldrb r0, [r5]
	ldrb r2, [r4]
	cmp r0, r2
	bne _08098048
	ldr r2, _0809803C @ =0x00000285
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809807A
	movs r6, #1
	rsbs r6, r6, #0
	adds r4, r6, #0
	movs r2, #0
	ldr r0, _08098040 @ =0x030046A0
	ldr r1, [r0]
	ldr r7, _08098044 @ =0x00003FF0
	adds r0, r3, r7
	ldrb r5, [r5]
	adds r0, r0, r5
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r1, #0x68
_0809800E:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	bne _08098018
	adds r6, r2, #0
_08098018:
	cmp r4, #0
	bge _08098022
	cmp r0, #0
	bge _08098022
	adds r4, r2, #0
_08098022:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _0809800E
	movs r7, #4
	cmp r6, #0
	bge _0809807A
	b _08098078
	.align 2, 0
_08098034: .4byte 0x00003AEE
_08098038: .4byte 0x00003AEB
_0809803C: .4byte 0x00000285
_08098040: .4byte 0x030046A0
_08098044: .4byte 0x00003FF0
_08098048:
	ldr r5, _0809806C @ =0x00000285
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08098074
	ldrb r1, [r4]
	ldr r0, _08098070 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5a
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, #0x10
	cmp r1, r0
	beq _0809807A
	cmp r1, #0xf
	bls _0809807A
	b _08098078
	.align 2, 0
_0809806C: .4byte 0x00000285
_08098070: .4byte 0x030046A0
_08098074:
	cmp r2, #0xf
	bls _0809807A
_08098078:
	movs r7, #1
_0809807A:
	cmp r7, #1
	beq _0809808C
	cmp r7, #4
	beq _08098096
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	adds r1, r2, #0
	b _0809809E
_0809808C:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #5
	b _0809809E
_08098096:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #2
_0809809E:
	bl FUN_0808c658
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
