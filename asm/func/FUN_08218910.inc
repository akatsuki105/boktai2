	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _08218934 @ =0x0000166C
	adds r2, r3, r0
	ldr r1, _08218938 @ =0x00001FE6
	adds r0, r3, r1
	ldrh r0, [r0]
	subs r0, #0x23
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x33
	bls _0821892A
	b _08218ADC
_0821892A:
	lsls r0, r0, #2
	ldr r1, _0821893C @ =_08218940
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08218934: .4byte 0x0000166C
_08218938: .4byte 0x00001FE6
_0821893C: .4byte _08218940
_08218940: @ jump table
	.4byte _08218A10 @ case 0
	.4byte _08218A1C @ case 1
	.4byte _08218A28 @ case 2
	.4byte _08218A34 @ case 3
	.4byte _08218A40 @ case 4
	.4byte _08218ADC @ case 5
	.4byte _08218ADC @ case 6
	.4byte _08218ADC @ case 7
	.4byte _08218ADC @ case 8
	.4byte _08218ADC @ case 9
	.4byte _08218ADC @ case 10
	.4byte _08218ADC @ case 11
	.4byte _08218ADC @ case 12
	.4byte _08218ADC @ case 13
	.4byte _08218ADC @ case 14
	.4byte _08218ADC @ case 15
	.4byte _08218ADC @ case 16
	.4byte _08218ADC @ case 17
	.4byte _08218ADC @ case 18
	.4byte _08218ADC @ case 19
	.4byte _08218ADC @ case 20
	.4byte _08218ADC @ case 21
	.4byte _08218ADC @ case 22
	.4byte _08218ADC @ case 23
	.4byte _08218ADC @ case 24
	.4byte _08218ADC @ case 25
	.4byte _08218ADC @ case 26
	.4byte _08218ADC @ case 27
	.4byte _08218ADC @ case 28
	.4byte _08218ADC @ case 29
	.4byte _08218ADC @ case 30
	.4byte _08218ADC @ case 31
	.4byte _08218ADC @ case 32
	.4byte _08218ADC @ case 33
	.4byte _08218ADC @ case 34
	.4byte _08218ADC @ case 35
	.4byte _08218ADC @ case 36
	.4byte _08218ADC @ case 37
	.4byte _08218ADC @ case 38
	.4byte _08218ADC @ case 39
	.4byte _08218A4C @ case 40
	.4byte _08218A58 @ case 41
	.4byte _08218A64 @ case 42
	.4byte _08218A70 @ case 43
	.4byte _08218A7C @ case 44
	.4byte _08218A88 @ case 45
	.4byte _08218A94 @ case 46
	.4byte _08218AA0 @ case 47
	.4byte _08218AAC @ case 48
	.4byte _08218AB8 @ case 49
	.4byte _08218AC4 @ case 50
	.4byte _08218AD0 @ case 51
_08218A10:
	ldr r4, _08218A18 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0
	b _08218B08
	.align 2, 0
_08218A18: .4byte 0x0000097A
_08218A1C:
	ldr r0, _08218A24 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #1
	b _08218B08
	.align 2, 0
_08218A24: .4byte 0x0000097A
_08218A28:
	ldr r4, _08218A30 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #2
	b _08218B08
	.align 2, 0
_08218A30: .4byte 0x0000097A
_08218A34:
	ldr r0, _08218A3C @ =0x0000097A
	adds r1, r2, r0
	movs r0, #3
	b _08218B08
	.align 2, 0
_08218A3C: .4byte 0x0000097A
_08218A40:
	ldr r4, _08218A48 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #4
	b _08218B08
	.align 2, 0
_08218A48: .4byte 0x0000097A
_08218A4C:
	ldr r0, _08218A54 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x28
	b _08218B08
	.align 2, 0
_08218A54: .4byte 0x0000097A
_08218A58:
	ldr r4, _08218A60 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x29
	b _08218B08
	.align 2, 0
_08218A60: .4byte 0x0000097A
_08218A64:
	ldr r0, _08218A6C @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x2a
	b _08218B08
	.align 2, 0
_08218A6C: .4byte 0x0000097A
_08218A70:
	ldr r4, _08218A78 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x2b
	b _08218B08
	.align 2, 0
_08218A78: .4byte 0x0000097A
_08218A7C:
	ldr r0, _08218A84 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x2c
	b _08218B08
	.align 2, 0
_08218A84: .4byte 0x0000097A
_08218A88:
	ldr r4, _08218A90 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x52
	b _08218B08
	.align 2, 0
_08218A90: .4byte 0x0000097A
_08218A94:
	ldr r0, _08218A9C @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x53
	b _08218B08
	.align 2, 0
_08218A9C: .4byte 0x0000097A
_08218AA0:
	ldr r4, _08218AA8 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x54
	b _08218B08
	.align 2, 0
_08218AA8: .4byte 0x0000097A
_08218AAC:
	ldr r0, _08218AB4 @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x54
	b _08218B08
	.align 2, 0
_08218AB4: .4byte 0x0000097A
_08218AB8:
	ldr r4, _08218AC0 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x55
	b _08218B08
	.align 2, 0
_08218AC0: .4byte 0x0000097A
_08218AC4:
	ldr r0, _08218ACC @ =0x0000097A
	adds r1, r2, r0
	movs r0, #0x56
	b _08218B08
	.align 2, 0
_08218ACC: .4byte 0x0000097A
_08218AD0:
	ldr r4, _08218AD8 @ =0x0000097A
	adds r1, r2, r4
	movs r0, #0x50
	b _08218B08
	.align 2, 0
_08218AD8: .4byte 0x0000097A
_08218ADC:
	ldr r1, _08218AF8 @ =0x00000974
	adds r0, r2, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #1
	bne _08218B00
	ldr r0, _08218AFC @ =0x0000097A
	adds r1, r2, r0
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, #0x4a
	bne _08218B00
	movs r0, #0x4e
	b _08218B08
	.align 2, 0
_08218AF8: .4byte 0x00000974
_08218AFC: .4byte 0x0000097A
_08218B00:
	ldr r0, _08218B1C @ =0x0000097A
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #5
_08218B08:
	strh r0, [r1]
	adds r0, r3, #0
	bl FUN_08217a10
	movs r0, #0xdc
	bl PlaySound_082406e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08218B1C: .4byte 0x0000097A
