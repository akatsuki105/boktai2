	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _0808A068 @ =0x085AC044
	adds r5, r4, #0
	adds r5, #0x4e
	ldrh r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	ldrh r0, [r5]
	cmp r0, #0
	beq _0808A0E0
	movs r5, #0
	adds r7, r4, #0
	adds r7, #0x5c
	adds r6, r4, #0
	adds r6, #0x60
	movs r0, #0x62
	adds r0, r0, r4
	mov ip, r0
_0808A046:
	movs r0, #0x2c
	muls r0, r5, r0
	adds r0, #0x74
	adds r2, r4, r0
	ldr r0, [r4, #0x6c]
	ldr r1, [r4, #0x70]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	movs r1, #0
	ldrsh r3, [r7, r1]
	cmp r5, #4
	bhi _0808A0C8
	lsls r0, r5, #2
	ldr r1, _0808A06C @ =_0808A070
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808A068: .4byte 0x085AC044
_0808A06C: .4byte _0808A070
_0808A070: @ jump table
	.4byte _0808A084 @ case 0
	.4byte _0808A09E @ case 1
	.4byte _0808A0A4 @ case 2
	.4byte _0808A0B0 @ case 3
	.4byte _0808A0BC @ case 4
_0808A084:
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldrh r1, [r2, #0x1e]
	adds r0, r0, r1
	strh r0, [r2, #0x1e]
	adds r0, r4, #0
	adds r0, #0x52
	ldrh r0, [r0]
	lsrs r0, r0, #4
	strb r0, [r2, #8]
	strb r0, [r2, #9]
	b _0808A0C8
_0808A09E:
	ldrh r0, [r2, #0x1c]
	subs r0, r0, r3
	b _0808A0C0
_0808A0A4:
	ldrh r0, [r2, #0x1c]
	adds r0, r0, r3
	strh r0, [r2, #0x1c]
	ldrh r0, [r2, #0x20]
	adds r0, r0, r3
	b _0808A0C6
_0808A0B0:
	ldrh r0, [r2, #0x1c]
	subs r0, r0, r3
	strh r0, [r2, #0x1c]
	ldrh r0, [r2, #0x20]
	adds r0, r0, r3
	b _0808A0C6
_0808A0BC:
	ldrh r0, [r2, #0x1c]
	adds r0, r0, r3
_0808A0C0:
	strh r0, [r2, #0x1c]
	ldrh r0, [r2, #0x20]
	subs r0, r0, r3
_0808A0C6:
	strh r0, [r2, #0x20]
_0808A0C8:
	ldrh r0, [r6]
	ldrh r1, [r2, #0x1c]
	adds r0, r0, r1
	strh r0, [r2, #0x1c]
	mov r1, ip
	ldrh r0, [r1]
	ldrh r1, [r2, #0x20]
	adds r0, r0, r1
	strh r0, [r2, #0x20]
	adds r5, #1
	cmp r5, #4
	ble _0808A046
_0808A0E0:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
