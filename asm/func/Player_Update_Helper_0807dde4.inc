	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0x8c
	lsls r0, r0, #2
	adds r7, r5, r0
	movs r6, #0
	ldr r0, _0807DE00 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	ldr r2, _0807DE04 @ =0x00000236
	adds r0, r5, r2
	b _0807E260
	.align 2, 0
_0807DE00: .4byte 0x03002B4C
_0807DE04: .4byte 0x00000236
_0807DE08:
	ldr r0, _0807DE38 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #0x2c
	bls _0807DE2E
	b _0807E256
_0807DE2E:
	lsls r0, r0, #2
	ldr r1, _0807DE3C @ =_0807DE40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807DE38: .4byte 0x03002B4C
_0807DE3C: .4byte _0807DE40
_0807DE40: @ jump table
	.4byte _0807DEF4 @ case 0
	.4byte _0807DEFC @ case 1
	.4byte _0807DF30 @ case 2
	.4byte _0807DF3C @ case 3
	.4byte _0807DF4A @ case 4
	.4byte _0807DF56 @ case 5
	.4byte _0807DF64 @ case 6
	.4byte _0807DFA0 @ case 7
	.4byte _0807DFAE @ case 8
	.4byte _0807DFBC @ case 9
	.4byte _0807DFC6 @ case 10
	.4byte _0807DFD4 @ case 11
	.4byte _0807DFE0 @ case 12
	.4byte _0807DFEC @ case 13
	.4byte _0807DFFA @ case 14
	.4byte _0807E00E @ case 15
	.4byte _0807E020 @ case 16
	.4byte _0807E038 @ case 17
	.4byte _0807E042 @ case 18
	.4byte _0807E054 @ case 19
	.4byte _0807E070 @ case 20
	.4byte _0807E062 @ case 21
	.4byte _0807E07E @ case 22
	.4byte _0807E08C @ case 23
	.4byte _0807E09A @ case 24
	.4byte _0807E0AC @ case 25
	.4byte _0807E15A @ case 26
	.4byte _0807E0B6 @ case 27
	.4byte _0807E1EC @ case 28
	.4byte _0807E0CE @ case 29
	.4byte _0807E108 @ case 30
	.4byte _0807E114 @ case 31
	.4byte _0807E13E @ case 32
	.4byte _0807E122 @ case 33
	.4byte _0807E130 @ case 34
	.4byte _0807E14C @ case 35
	.4byte _0807E166 @ case 36
	.4byte _0807E170 @ case 37
	.4byte _0807E180 @ case 38
	.4byte _0807E18A @ case 39
	.4byte _0807E1C4 @ case 40
	.4byte _0807E1D0 @ case 41
	.4byte _0807E1A8 @ case 42
	.4byte _0807E192 @ case 43
	.4byte _0807E1BC @ case 44
_0807DEF4:
	adds r0, r5, #0
	bl FUN_0807b8dc
	b _0807E1D8
_0807DEFC:
	ldrh r0, [r4, #8]
	ldr r3, _0807DF28 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _0807DF2C @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #4]
	ldrh r1, [r4, #0xc]
	ldr r0, [sp, #8]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r5, #0
	add r1, sp, #4
	bl FUN_0807b8d0
	b _0807E1D8
	.align 2, 0
_0807DF28: .4byte 0xFFFF0000
_0807DF2C: .4byte 0x0000FFFF
_0807DF30:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	bl FUN_0807b910
	b _0807E1D8
_0807DF3C:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807b9dc
	b _0807E178
_0807DF4A:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	bl FUN_0807ba14
	b _0807E1D8
_0807DF56:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807ba50
	b _0807E178
_0807DF64:
	ldrh r0, [r4, #8]
	ldr r3, _0807DF98 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0xc]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _0807DF9C @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r2, [r4, #0xc]
	add r1, sp, #0xc
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r3, #1
	rsbs r3, r3, #0
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807ba94
	b _0807E178
	.align 2, 0
_0807DF98: .4byte 0xFFFF0000
_0807DF9C: .4byte 0x0000FFFF
_0807DFA0:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807bbb0
	b _0807E178
_0807DFAE:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807bc14
	b _0807E178
_0807DFBC:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807bc64
	b _0807E178
_0807DFC6:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807bcb0
	b _0807E178
_0807DFD4:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	bl FUN_0807bd44
	b _0807E1D8
_0807DFE0:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	bl FUN_0807bcfc
	b _0807E1D8
_0807DFEC:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807bd84
	b _0807E178
_0807DFFA:
	movs r0, #8
	ldrsh r2, [r4, r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0807bb3c
	b _0807E1D8
_0807E00E:
	movs r2, #8
	ldrsh r1, [r4, r2]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0807bee0
	b _0807E178
_0807E020:
	movs r2, #8
	ldrsh r1, [r4, r2]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	movs r0, #0xc
	ldrsh r3, [r4, r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_0807bfa4
	b _0807E178
_0807E038:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807c048
	b _0807E178
_0807E042:
	movs r2, #8
	ldrsh r1, [r4, r2]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0807c084
	b _0807E178
_0807E054:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c200
	b _0807E178
_0807E062:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c36c
	b _0807E178
_0807E070:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c30c
	b _0807E178
_0807E07E:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c5f0
	b _0807E178
_0807E08C:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c634
	b _0807E178
_0807E09A:
	movs r0, #8
	ldrsh r1, [r4, r0]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0807c748
	b _0807E178
_0807E0AC:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807c798
	b _0807E178
_0807E0B6:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807cc84
	adds r4, r0, #0
	adds r0, r5, #0
	bl FUN_08072670
	cmp r4, #0
	beq _0807E0CC
	b _0807E256
_0807E0CC:
	b _0807E1DE
_0807E0CE:
	ldrh r0, [r4, #8]
	ldr r3, _0807E100 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x14]
	ldrh r2, [r4, #0xa]
	lsls r2, r2, #0x10
	ldr r0, _0807E104 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x14]
	ldrh r2, [r4, #0xc]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0807c88c
	b _0807E178
	.align 2, 0
_0807E100: .4byte 0xFFFF0000
_0807E104: .4byte 0x0000FFFF
_0807E108:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	bl FUN_0807c8d4
	b _0807E1D8
_0807E114:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807c9ac
	b _0807E178
_0807E122:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807ca24
	b _0807E178
_0807E130:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807ca9c
	b _0807E178
_0807E13E:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807cb14
	b _0807E178
_0807E14C:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0807cb8c
	b _0807E178
_0807E15A:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	bl FUN_0807cc14
	b _0807E1D8
_0807E166:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807c928
	b _0807E178
_0807E170:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0807c968
_0807E178:
	adds r0, r5, #0
	bl FUN_08072670
	b _0807E256
_0807E180:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_0807cd24
	b _0807E1D8
_0807E18A:
	adds r0, r5, #0
	bl FUN_0807ceb8
	b _0807E1D8
_0807E192:
	movs r0, #8
	ldrsh r1, [r4, r0]
	ldr r2, _0807E1A4 @ =0x00000121
	adds r1, r1, r2
	adds r0, r5, #0
	bl FUN_0807b890
	b _0807E1D8
	.align 2, 0
_0807E1A4: .4byte 0x00000121
_0807E1A8:
	movs r0, #8
	ldrsh r1, [r4, r0]
	ldr r2, _0807E1B8 @ =0x00000121
	adds r1, r1, r2
	adds r0, r5, #0
	bl FUN_0807b8a8
	b _0807E1D8
	.align 2, 0
_0807E1B8: .4byte 0x00000121
_0807E1BC:
	adds r0, r5, #0
	bl FUN_0807b8c0
	b _0807E1D8
_0807E1C4:
	ldr r0, _0807E1CC @ =0x000004AD
	adds r1, r5, r0
	movs r0, #1
	b _0807E1D6
	.align 2, 0
_0807E1CC: .4byte 0x000004AD
_0807E1D0:
	ldr r2, _0807E1E8 @ =0x000004AD
	adds r1, r5, r2
	movs r0, #0
_0807E1D6:
	strb r0, [r1]
_0807E1D8:
	adds r0, r5, #0
	bl FUN_08072670
_0807E1DE:
	adds r0, r5, #0
	bl FUN_0807268c
	b _0807E256
	.align 2, 0
_0807E1E8: .4byte 0x000004AD
_0807E1EC:
	movs r1, #8
	ldrsh r0, [r4, r1]
	cmp r0, #8
	bhi _0807E24A
	lsls r0, r0, #2
	ldr r1, _0807E200 @ =_0807E204
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807E200: .4byte _0807E204
_0807E204: @ jump table
	.4byte _0807E228 @ case 0
	.4byte _0807E228 @ case 1
	.4byte _0807E228 @ case 2
	.4byte _0807E228 @ case 3
	.4byte _0807E238 @ case 4
	.4byte _0807E238 @ case 5
	.4byte _0807E228 @ case 6
	.4byte _0807E228 @ case 7
	.4byte _0807E228 @ case 8
_0807E228:
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0807cec4
	b _0807E24A
_0807E238:
	movs r0, #8
	ldrsh r1, [r4, r0]
	movs r0, #0xa
	ldrsh r2, [r4, r0]
	movs r0, #0xc
	ldrsh r3, [r4, r0]
	adds r0, r5, #0
	bl FUN_0807cec4
_0807E24A:
	adds r0, r5, #0
	bl FUN_08072670
	adds r0, r5, #0
	bl FUN_0807268c
_0807E256:
	adds r6, #1
	ldr r0, _0807E274 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r7, #6
_0807E260:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0807E26C
	b _0807DE08
_0807E26C:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807E274: .4byte 0x03002B4C
