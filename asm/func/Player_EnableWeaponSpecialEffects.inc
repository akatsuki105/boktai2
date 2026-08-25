	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	movs r1, #0
	ldr r2, _08064128 @ =0x00000A9C
	adds r0, r3, r2
	movs r5, #2
_080640EA:
	str r1, [r0]
	str r1, [r0, #0xc]
	str r1, [r0, #0x18]
	adds r0, #4
	subs r5, #1
	cmp r5, #0
	bge _080640EA
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0x10
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	movs r5, #0
	adds r4, r0, #0
_0806410C:
	lsls r0, r5, #2
	adds r1, r6, r0
	ldrb r1, [r1, #0x18]
	subs r1, #1
	adds r2, r0, #0
	cmp r1, #0x1e
	bls _0806411C
	b _080643C2
_0806411C:
	lsls r0, r1, #2
	ldr r1, _0806412C @ =_08064130
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08064128: .4byte 0x00000A9C
_0806412C: .4byte _08064130
_08064130: @ jump table
	.4byte _080641AC @ case 0
	.4byte _080641D4 @ case 1
	.4byte _0806424C @ case 2
	.4byte _08064260 @ case 3
	.4byte _0806438A @ case 4
	.4byte _080643A0 @ case 5
	.4byte _080643B4 @ case 6
	.4byte _080641FC @ case 7
	.4byte _08064210 @ case 8
	.4byte _080641E8 @ case 9
	.4byte _08064238 @ case 10
	.4byte _08064224 @ case 11
	.4byte _080641C0 @ case 12
	.4byte _080641AC @ case 13
	.4byte _080641D4 @ case 14
	.4byte _08064288 @ case 15
	.4byte _08064274 @ case 16
	.4byte _08064300 @ case 17
	.4byte _08064314 @ case 18
	.4byte _08064328 @ case 19
	.4byte _0806433C @ case 20
	.4byte _0806429C @ case 21
	.4byte _080642B0 @ case 22
	.4byte _080642C4 @ case 23
	.4byte _080642D8 @ case 24
	.4byte _080642EC @ case 25
	.4byte _08064350 @ case 26
	.4byte _08064364 @ case 27
	.4byte _08064380 @ case 28
	.4byte _0806437C @ case 29
	.4byte _08064378 @ case 30
_080641AC:
	ldr r1, _080641B8 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080641BC @ =FUN_08063d00
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080641B8: .4byte 0x00000A9C
_080641BC: .4byte FUN_08063d00
_080641C0:
	ldr r1, _080641CC @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080641D0 @ =FUN_08063d18
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080641CC: .4byte 0x00000A9C
_080641D0: .4byte FUN_08063d18
_080641D4:
	ldr r1, _080641E0 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080641E4 @ =FUN_08063d70
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080641E0: .4byte 0x00000A9C
_080641E4: .4byte FUN_08063d70
_080641E8:
	ldr r1, _080641F4 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080641F8 @ =FUN_08063d84
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080641F4: .4byte 0x00000A9C
_080641F8: .4byte FUN_08063d84
_080641FC:
	ldr r1, _08064208 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _0806420C @ =FUN_08063d94
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064208: .4byte 0x00000A9C
_0806420C: .4byte FUN_08063d94
_08064210:
	ldr r1, _0806421C @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064220 @ =FUN_08063da0
	str r1, [r0]
	b _080643C2
	.align 2, 0
_0806421C: .4byte 0x00000A9C
_08064220: .4byte FUN_08063da0
_08064224:
	ldr r1, _08064230 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064234 @ =FUN_08063db0
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064230: .4byte 0x00000A9C
_08064234: .4byte FUN_08063db0
_08064238:
	ldr r1, _08064244 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064248 @ =FUN_08063dd4
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064244: .4byte 0x00000A9C
_08064248: .4byte FUN_08063dd4
_0806424C:
	ldr r1, _08064258 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _0806425C @ =FUN_08063df8
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064258: .4byte 0x00000A9C
_0806425C: .4byte FUN_08063df8
_08064260:
	ldr r1, _0806426C @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064270 @ =FUN_08063e1c
	str r1, [r0]
	b _080643C2
	.align 2, 0
_0806426C: .4byte 0x00000A9C
_08064270: .4byte FUN_08063e1c
_08064274:
	ldr r1, _08064280 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064284 @ =FUN_08063e40
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064280: .4byte 0x00000AB4
_08064284: .4byte FUN_08063e40
_08064288:
	ldr r1, _08064294 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064298 @ =FUN_08063ed8
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064294: .4byte 0x00000AB4
_08064298: .4byte FUN_08063ed8
_0806429C:
	ldr r1, _080642A8 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080642AC @ =FUN_08063f10
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080642A8: .4byte 0x00000AB4
_080642AC: .4byte FUN_08063f10
_080642B0:
	ldr r1, _080642BC @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080642C0 @ =FUN_08063f28
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080642BC: .4byte 0x00000AB4
_080642C0: .4byte FUN_08063f28
_080642C4:
	ldr r1, _080642D0 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080642D4 @ =FUN_08063f40
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080642D0: .4byte 0x00000AB4
_080642D4: .4byte FUN_08063f40
_080642D8:
	ldr r1, _080642E4 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080642E8 @ =FUN_08063f58
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080642E4: .4byte 0x00000AB4
_080642E8: .4byte FUN_08063f58
_080642EC:
	ldr r1, _080642F8 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080642FC @ =FUN_08063f70
	str r1, [r0]
	b _080643C2
	.align 2, 0
_080642F8: .4byte 0x00000AB4
_080642FC: .4byte FUN_08063f70
_08064300:
	ldr r1, _0806430C @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064310 @ =FUN_08063f88
	str r1, [r0]
	b _080643C2
	.align 2, 0
_0806430C: .4byte 0x00000AB4
_08064310: .4byte FUN_08063f88
_08064314:
	ldr r1, _08064320 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064324 @ =FUN_08063fa0
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064320: .4byte 0x00000AB4
_08064324: .4byte FUN_08063fa0
_08064328:
	ldr r1, _08064334 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064338 @ =FUN_08063fb8
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064334: .4byte 0x00000AB4
_08064338: .4byte FUN_08063fb8
_0806433C:
	ldr r1, _08064348 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _0806434C @ =FUN_08063fd0
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064348: .4byte 0x00000AB4
_0806434C: .4byte FUN_08063fd0
_08064350:
	ldr r1, _0806435C @ =0x00000AA8
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064360 @ =CheckNamakuraProc
	str r1, [r0]
	b _080643C2
	.align 2, 0
_0806435C: .4byte 0x00000AA8
_08064360: .4byte CheckNamakuraProc
_08064364:
	ldr r1, _08064370 @ =0x00000AA8
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _08064374 @ =CheckParalyzeProc
	str r1, [r0]
	b _080643C2
	.align 2, 0
_08064370: .4byte 0x00000AA8
_08064374: .4byte CheckParalyzeProc
_08064378:
	movs r1, #1
	b _08064382
_0806437C:
	movs r1, #2
	b _08064382
_08064380:
	movs r1, #4
_08064382:
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	b _080643C2
_0806438A:
	movs r1, #8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r2, _0806439C @ =0x00000A95
	adds r1, r3, r2
	movs r0, #0
	b _080643C0
	.align 2, 0
_0806439C: .4byte 0x00000A95
_080643A0:
	movs r1, #8
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r0, _080643B0 @ =0x00000A95
	adds r1, r3, r0
	movs r0, #4
	b _080643C0
	.align 2, 0
_080643B0: .4byte 0x00000A95
_080643B4:
	movs r0, #8
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	ldr r2, _080643D0 @ =0x00000A95
	adds r1, r3, r2
_080643C0:
	strb r0, [r1]
_080643C2:
	adds r5, #1
	cmp r5, #2
	bgt _080643CA
	b _0806410C
_080643CA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080643D0: .4byte 0x00000A95
