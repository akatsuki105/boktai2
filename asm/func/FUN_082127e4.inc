	push {r4, lr}
	sub sp, #4
	adds r1, r0, #0
	adds r4, r1, #0
	adds r4, #0x94
	ldr r0, _08212838 @ =0x00000414
	adds r2, r1, r0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _08212804
	movs r0, #1
	strb r0, [r2]
_08212804:
	ldr r1, [r1, #0x38]
	ldrb r2, [r2]
	movs r0, #3
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0821283C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08212840 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bhi _0821289C
	lsls r0, r0, #2
	ldr r1, _08212844 @ =_08212848
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08212838: .4byte 0x00000414
_0821283C: .4byte 0x030046A0
_08212840: .4byte 0x00000942
_08212844: .4byte _08212848
_08212848: @ jump table
	.4byte _08212874 @ case 0
	.4byte _08212878 @ case 1
	.4byte _0821287C @ case 2
	.4byte _08212880 @ case 3
	.4byte _08212884 @ case 4
	.4byte _08212888 @ case 5
	.4byte _0821289C @ case 6
	.4byte _0821288C @ case 7
	.4byte _08212890 @ case 8
	.4byte _08212894 @ case 9
	.4byte _08212898 @ case 10
_08212874:
	movs r1, #0xe
	b _0821289E
_08212878:
	movs r1, #0xd
	b _0821289E
_0821287C:
	movs r1, #0xc
	b _0821289E
_08212880:
	movs r1, #0xb
	b _0821289E
_08212884:
	movs r1, #0xa
	b _0821289E
_08212888:
	movs r1, #9
	b _0821289E
_0821288C:
	movs r1, #7
	b _0821289E
_08212890:
	movs r1, #6
	b _0821289E
_08212894:
	movs r1, #5
	b _0821289E
_08212898:
	movs r1, #4
	b _0821289E
_0821289C:
	movs r1, #8
_0821289E:
	ldr r2, _082128AC @ =0x00000381
	adds r0, r4, r2
	strb r1, [r0]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082128AC: .4byte 0x00000381
