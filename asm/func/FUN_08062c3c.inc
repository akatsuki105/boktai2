	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08062C4E
	b _08063064
_08062C4E:
	lsls r0, r0, #2
	ldr r1, _08062C58 @ =_08062C5C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08062C58: .4byte _08062C5C
_08062C5C: @ jump table
	.4byte _08062C74 @ case 0
	.4byte _08062D40 @ case 1
	.4byte _08062E0C @ case 2
	.4byte _08062EE0 @ case 3
	.4byte _08062FAC @ case 4
	.4byte _08063020 @ case 5
_08062C74:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08062C94
	ldr r5, _08062C90 @ =0x00000938
	adds r1, r4, r5
	movs r0, #0x94
	lsls r0, r0, #1
	b _08062CEA
	.align 2, 0
_08062C90: .4byte 0x00000938
_08062C94:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08062CB0
	ldr r0, _08062CA8 @ =0x00000938
	adds r1, r4, r0
	ldr r0, _08062CAC @ =0x00000129
	b _08062CEA
	.align 2, 0
_08062CA8: .4byte 0x00000938
_08062CAC: .4byte 0x00000129
_08062CB0:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08062CC8
	ldr r2, _08062CC4 @ =0x00000938
	adds r1, r4, r2
	movs r0, #0x95
	lsls r0, r0, #1
	b _08062CEA
	.align 2, 0
_08062CC4: .4byte 0x00000938
_08062CC8:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08062CE4
	ldr r5, _08062CDC @ =0x00000938
	adds r1, r4, r5
	ldr r0, _08062CE0 @ =0x0000012B
	b _08062CEA
	.align 2, 0
_08062CDC: .4byte 0x00000938
_08062CE0: .4byte 0x0000012B
_08062CE4:
	ldr r0, _08062D24 @ =0x00000938
	adds r1, r4, r0
	movs r0, #0x1d
_08062CEA:
	strh r0, [r1]
	ldr r2, _08062D28 @ =0x0000093A
	adds r1, r4, r2
	ldr r0, _08062D2C @ =0x00000121
	strh r0, [r1]
	ldr r5, _08062D30 @ =0x0000093C
	adds r1, r4, r5
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _08062D34 @ =0x0000093E
	adds r1, r4, r0
	ldr r0, _08062D38 @ =0x00000123
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	adds r0, #1
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	movs r0, #0x1f
	strh r0, [r1]
	ldr r0, _08062D3C @ =0x00000944
	adds r1, r4, r0
	movs r0, #0x21
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	b _08063060
	.align 2, 0
_08062D24: .4byte 0x00000938
_08062D28: .4byte 0x0000093A
_08062D2C: .4byte 0x00000121
_08062D30: .4byte 0x0000093C
_08062D34: .4byte 0x0000093E
_08062D38: .4byte 0x00000123
_08062D3C: .4byte 0x00000944
_08062D40:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r5, #0xde
	lsls r5, r5, #2
	adds r1, r4, r5
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08062D60
	ldr r0, _08062D5C @ =0x00000938
	adds r1, r4, r0
	movs r0, #0x94
	lsls r0, r0, #1
	b _08062DB6
	.align 2, 0
_08062D5C: .4byte 0x00000938
_08062D60:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08062D7C
	ldr r2, _08062D74 @ =0x00000938
	adds r1, r4, r2
	ldr r0, _08062D78 @ =0x00000129
	b _08062DB6
	.align 2, 0
_08062D74: .4byte 0x00000938
_08062D78: .4byte 0x00000129
_08062D7C:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08062D94
	ldr r5, _08062D90 @ =0x00000938
	adds r1, r4, r5
	movs r0, #0x95
	lsls r0, r0, #1
	b _08062DB6
	.align 2, 0
_08062D90: .4byte 0x00000938
_08062D94:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08062DB0
	ldr r0, _08062DA8 @ =0x00000938
	adds r1, r4, r0
	ldr r0, _08062DAC @ =0x0000012B
	b _08062DB6
	.align 2, 0
_08062DA8: .4byte 0x00000938
_08062DAC: .4byte 0x0000012B
_08062DB0:
	ldr r2, _08062DF0 @ =0x00000938
	adds r1, r4, r2
	movs r0, #0x26
_08062DB6:
	strh r0, [r1]
	ldr r5, _08062DF4 @ =0x0000093A
	adds r1, r4, r5
	ldr r0, _08062DF8 @ =0x00000121
	strh r0, [r1]
	ldr r0, _08062DFC @ =0x0000093C
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r2, _08062E00 @ =0x0000093E
	adds r1, r4, r2
	ldr r0, _08062E04 @ =0x00000123
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	adds r0, #1
	strh r0, [r1]
	ldr r0, _08062E08 @ =0x00000942
	adds r1, r4, r0
	movs r0, #0x1f
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	movs r0, #0x21
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	b _08063060
	.align 2, 0
_08062DF0: .4byte 0x00000938
_08062DF4: .4byte 0x0000093A
_08062DF8: .4byte 0x00000121
_08062DFC: .4byte 0x0000093C
_08062E00: .4byte 0x0000093E
_08062E04: .4byte 0x00000123
_08062E08: .4byte 0x00000942
_08062E0C:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08062E30
	ldr r5, _08062E28 @ =0x00000938
	adds r1, r4, r5
	ldr r0, _08062E2C @ =0x0000026F
	b _08062E86
	.align 2, 0
_08062E28: .4byte 0x00000938
_08062E2C: .4byte 0x0000026F
_08062E30:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08062E48
	ldr r0, _08062E44 @ =0x00000938
	adds r1, r4, r0
	movs r0, #0x9c
	lsls r0, r0, #2
	b _08062E86
	.align 2, 0
_08062E44: .4byte 0x00000938
_08062E48:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08062E64
	ldr r2, _08062E5C @ =0x00000938
	adds r1, r4, r2
	ldr r0, _08062E60 @ =0x0000026E
	b _08062E86
	.align 2, 0
_08062E5C: .4byte 0x00000938
_08062E60: .4byte 0x0000026E
_08062E64:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08062E80
	ldr r5, _08062E78 @ =0x00000938
	adds r1, r4, r5
	ldr r0, _08062E7C @ =0x00000271
	b _08062E86
	.align 2, 0
_08062E78: .4byte 0x00000938
_08062E7C: .4byte 0x00000271
_08062E80:
	ldr r0, _08062EC4 @ =0x00000938
	adds r1, r4, r0
	ldr r0, _08062EC8 @ =0x00000266
_08062E86:
	strh r0, [r1]
	ldr r2, _08062ECC @ =0x0000093A
	adds r1, r4, r2
	ldr r0, _08062ED0 @ =0x0000026D
	strh r0, [r1]
	ldr r5, _08062ED4 @ =0x0000093C
	adds r1, r4, r5
	subs r0, #2
	strh r0, [r1]
	ldr r0, _08062ED8 @ =0x0000093E
	adds r1, r4, r0
	movs r0, #0x9a
	lsls r0, r0, #2
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	adds r0, #1
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	adds r0, #1
	strh r0, [r1]
	ldr r0, _08062EDC @ =0x00000944
	adds r1, r4, r0
	movs r0, #0x9b
	lsls r0, r0, #2
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	subs r0, #5
	b _08063062
	.align 2, 0
_08062EC4: .4byte 0x00000938
_08062EC8: .4byte 0x00000266
_08062ECC: .4byte 0x0000093A
_08062ED0: .4byte 0x0000026D
_08062ED4: .4byte 0x0000093C
_08062ED8: .4byte 0x0000093E
_08062EDC: .4byte 0x00000944
_08062EE0:
	movs r0, #0x80
	lsls r0, r0, #0xd
	movs r5, #0xde
	lsls r5, r5, #2
	adds r1, r4, r5
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08062F00
	ldr r0, _08062EFC @ =0x00000938
	adds r1, r4, r0
	movs r0, #0x94
	lsls r0, r0, #1
	b _08062F56
	.align 2, 0
_08062EFC: .4byte 0x00000938
_08062F00:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08062F1C
	ldr r2, _08062F14 @ =0x00000938
	adds r1, r4, r2
	ldr r0, _08062F18 @ =0x00000129
	b _08062F56
	.align 2, 0
_08062F14: .4byte 0x00000938
_08062F18: .4byte 0x00000129
_08062F1C:
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08062F34
	ldr r5, _08062F30 @ =0x00000938
	adds r1, r4, r5
	movs r0, #0x95
	lsls r0, r0, #1
	b _08062F56
	.align 2, 0
_08062F30: .4byte 0x00000938
_08062F34:
	movs r0, #0x80
	lsls r0, r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _08062F50
	ldr r0, _08062F48 @ =0x00000938
	adds r1, r4, r0
	ldr r0, _08062F4C @ =0x0000012B
	b _08062F56
	.align 2, 0
_08062F48: .4byte 0x00000938
_08062F4C: .4byte 0x0000012B
_08062F50:
	ldr r2, _08062F90 @ =0x00000938
	adds r1, r4, r2
	movs r0, #0x1d
_08062F56:
	strh r0, [r1]
	ldr r5, _08062F94 @ =0x0000093A
	adds r1, r4, r5
	ldr r0, _08062F98 @ =0x00000121
	strh r0, [r1]
	ldr r0, _08062F9C @ =0x0000093C
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r2, _08062FA0 @ =0x0000093E
	adds r1, r4, r2
	ldr r0, _08062FA4 @ =0x00000123
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	adds r0, #1
	strh r0, [r1]
	ldr r0, _08062FA8 @ =0x00000942
	adds r1, r4, r0
	movs r0, #0x1f
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	movs r0, #0x21
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	b _08063060
	.align 2, 0
_08062F90: .4byte 0x00000938
_08062F94: .4byte 0x0000093A
_08062F98: .4byte 0x00000121
_08062F9C: .4byte 0x0000093C
_08062FA0: .4byte 0x0000093E
_08062FA4: .4byte 0x00000123
_08062FA8: .4byte 0x00000942
_08062FAC:
	ldr r0, _08063004 @ =0x00000387
	adds r2, r4, r0
	ldr r5, _08063008 @ =0x00000207
	adds r1, r5, #0
	ldrb r0, [r2]
	adds r3, r1, r0
	ldr r5, _0806300C @ =0x00000938
	adds r0, r4, r5
	strh r3, [r0]
	ldr r0, _08063010 @ =0x0000093A
	adds r3, r4, r0
	ldr r0, _08063014 @ =0x0000020F
	strh r0, [r3]
	ldrb r5, [r2]
	adds r3, r1, r5
	ldr r5, _08063018 @ =0x0000093C
	adds r0, r4, r5
	strh r3, [r0]
	ldrb r0, [r2]
	adds r3, r1, r0
	adds r5, #2
	adds r0, r4, r5
	strh r3, [r0]
	ldrb r0, [r2]
	adds r3, r1, r0
	adds r5, #2
	adds r0, r4, r5
	strh r3, [r0]
	ldrb r0, [r2]
	adds r3, r1, r0
	adds r5, #2
	adds r0, r4, r5
	strh r3, [r0]
	ldrb r0, [r2]
	adds r3, r1, r0
	adds r5, #2
	adds r0, r4, r5
	strh r3, [r0]
	ldrb r2, [r2]
	adds r1, r1, r2
	ldr r2, _0806301C @ =0x00000946
	adds r0, r4, r2
	strh r1, [r0]
	b _08063064
	.align 2, 0
_08063004: .4byte 0x00000387
_08063008: .4byte 0x00000207
_0806300C: .4byte 0x00000938
_08063010: .4byte 0x0000093A
_08063014: .4byte 0x0000020F
_08063018: .4byte 0x0000093C
_0806301C: .4byte 0x00000946
_08063020:
	ldr r5, _0806306C @ =0x00000938
	adds r1, r4, r5
	movs r0, #0x27
	strh r0, [r1]
	ldr r0, _08063070 @ =0x0000093A
	adds r1, r4, r0
	ldr r0, _08063074 @ =0x00000121
	strh r0, [r1]
	ldr r2, _08063078 @ =0x0000093C
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	ldr r0, _0806307C @ =0x00000123
	strh r0, [r1]
	movs r0, #0x94
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x92
	lsls r0, r0, #1
	strh r0, [r1]
	adds r2, #6
	adds r1, r4, r2
	movs r0, #0x1f
	strh r0, [r1]
	adds r5, #6
	adds r1, r4, r5
	movs r0, #0x21
	strh r0, [r1]
	ldr r0, _08063080 @ =0x00000946
	adds r1, r4, r0
_08063060:
	movs r0, #0x1e
_08063062:
	strh r0, [r1]
_08063064:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806306C: .4byte 0x00000938
_08063070: .4byte 0x0000093A
_08063074: .4byte 0x00000121
_08063078: .4byte 0x0000093C
_0806307C: .4byte 0x00000123
_08063080: .4byte 0x00000946
